#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
	x = 0;
	y = 0;
	prevX = 0;
	prevY = 0;
	mapWidth = 0;
	mapHeight = 0;
	moveTime = enemyConstants.enemyMoveTime;
	currentTime = 0;
}

Enemy::Enemy(cus x, cus y) {
	setInitialPosition(x, y);
}

void Enemy::setInitialPosition(cus x, cus y) {
	this->x = x;
	this->y = y;
	prevX = x;
	prevY = y;
}

void Enemy::setPosition(cus x, cus y) {
	prevX = this->x;
	prevY = this->y;
	this->x = x;
	this->y = y;
}

void Enemy::updateTime(unsigned newTime) {
	currentTime += newTime;
}

void Enemy::move() {
	if (!path.empty()) {
		prevX = x;
		prevY = y;
		x = path.front().first;
		y = path.front().second;
		path.pop_front();
	}
}

void Enemy::copy(const Enemy& other) {
	x = other.x;
	y = other.y;
	prevX = other.prevX;
	prevY = other.prevY;
	path = other.path;
	mapWidth = other.mapWidth;
	mapHeight = other.mapHeight;
	moveTime = other.moveTime;
	currentTime = other.currentTime;
}

Enemy::Enemy(const Enemy& other) {
	copy(other);
}

Enemy& Enemy::operator=(const Enemy& other) {
	if (this != &other) {
		copy(other);
	}
	return *this;
}

unsigned short Enemy::getX() {
	return x;
}

unsigned short Enemy::getY() {
	return y;
}

unsigned short Enemy::getPrevX() {
	return prevX;
}

unsigned short Enemy::getPrevY() {
	return prevY;
}

void Enemy::setBoundaries(cus width, cus height) {
	mapWidth = width;
	mapHeight = height;
}

void Enemy::tracePathToPlayer(const GameMap& walkMap, const bool recalculate, cus& pX, cus& pY) {
	if (isValidPosition(walkMap, pX, pY)) {
		if (pX == x && pY == y)
			return;
		if (recalculate) {
			while (!path.empty())
				path.pop_front();
			findPath(walkMap, pX, pY);
		}
		else {
			Coordinate newPair(pX, pY);
			path.push_back(newPair);
		}
	}
}

bool Enemy::isValidPosition(const GameMap& walkMap, cus& pX, cus& pY) {
	if ((pY >= 0) && (pY < mapHeight) && (pX >= 0) && (pX < mapWidth))
		if (isPassable(walkMap, pX, pY))
			return true;
	return false;
}

bool Enemy::hasFoundPlayerCell(cus& pX, cus& pY, cus& eX, cus& eY) {
	if (pX == eX && pY == eY)
		return true;
	return false;
}

void Enemy::findPath(const GameMap& walkMap, cus& pX, cus& pY) {
	if (currentTime < moveTime) {
		return;
	}
	currentTime = 0;
	if (pX == x && pY == y)
		path.push_back(std::make_pair(pX, pY));

	AdjecencyMap bufferMap;
	for (unsigned i = 0; i < walkMap.size(); ++i) {
		std::vector<unsigned> row;
		for (unsigned p = 0; p < walkMap[i].size(); ++p)
			row.push_back(0);
		bufferMap.push_back(row);
	}

	std::queue<Coordinate> current;
	std::queue<Coordinate> next;
	bool found = false;
	current.push(std::make_pair(x, y));
	bufferMap[y][x] = 1;
	int counter = 2;
	while (!found) {
		while (!current.empty()) {
			Coordinate newC = current.front();
			current.pop();

			if (isValidPosition(walkMap, newC.first + 1, newC.second) && !bufferMap[newC.second][newC.first + 1]) {// right
				bufferMap[newC.second][newC.first + 1] = counter;
				next.push(std::make_pair(newC.first + 1, newC.second));
				if (hasFoundPlayerCell(pX, pY, newC.first + 1, newC.second)) {
					found = true;
					break;
				}
			}

			if (isValidPosition(walkMap, newC.first - 1, newC.second) && !bufferMap[newC.second][newC.first - 1]) {// left
				bufferMap[newC.second][newC.first - 1] = counter;
				next.push(std::make_pair(newC.first - 1, newC.second));
				if (hasFoundPlayerCell(pX, pY, newC.first - 1, newC.second)) {
					found = true;
					break;
				}
			}

			if (isValidPosition(walkMap, newC.first, newC.second - 1) && !bufferMap[newC.second - 1][newC.first]) {// top
				bufferMap[newC.second - 1][newC.first] = counter;
				next.push(std::make_pair(newC.first, newC.second - 1));

				if (hasFoundPlayerCell(pX, pY, newC.first, newC.second - 1)) {
					found = true;
					break;
				}
			}

			if (isValidPosition(walkMap, newC.first, newC.second + 1) && !bufferMap[newC.second + 1][newC.first]) {// bot
				bufferMap[newC.second + 1][newC.first] = counter;
				next.push(std::make_pair(newC.first, newC.second + 1));
				if (hasFoundPlayerCell(pX, pY, newC.first, newC.second + 1)) {
					found = true;
					break;
				}
			}
		}

		if (current.empty()) {
			current = next;
			counter++;
		}

		if (found) {
			break;
		}
	}

	Coordinate currentCell(pX, pY);
	Coordinate result;

	path.push_front(currentCell);
	while (true) {
		getMinimalPosition(currentCell, result, bufferMap, walkMap);
		if (result.first == x && result.second == y)
			break;
		path.push_front(result);

		currentCell = result;
	}
}

bool Enemy::isPassable(const GameMap& walkMap, cus& pX, cus& pY) {
	if (!walkMap[pY][pX])
		return true;
	return false;
}

void Enemy::getMinimalPosition(Coordinate& givenCoordinate, Coordinate& result, const AdjecencyMap& map, const GameMap& walkMap) {
	unsigned short minVal = 16000;
	unsigned short minX = 0;
	unsigned short minY = 0;

	if (isValidPosition(walkMap, givenCoordinate.first + 1, givenCoordinate.second)) { // right
		if (map[givenCoordinate.second][givenCoordinate.first + 1] < minVal && map[givenCoordinate.second][givenCoordinate.first + 1] != 0) {
			minVal = map[givenCoordinate.second][givenCoordinate.first + 1];
			minX = givenCoordinate.first + 1;
			minY = givenCoordinate.second;
		}
	}
	if (isValidPosition(walkMap, givenCoordinate.first - 1, givenCoordinate.second)) { // left
		if (map[givenCoordinate.second][givenCoordinate.first - 1] < minVal && map[givenCoordinate.second][givenCoordinate.first - 1] != 0) {
			minVal = map[givenCoordinate.second][givenCoordinate.first - 1];
			minX = givenCoordinate.first - 1;
			minY = givenCoordinate.second;
		}
	}
	if (isValidPosition(walkMap, givenCoordinate.first, givenCoordinate.second + 1)) { // bot
		if (map[givenCoordinate.second + 1][givenCoordinate.first] < minVal && map[givenCoordinate.second + 1][givenCoordinate.first] != 0) {
			minVal = map[givenCoordinate.second + 1][givenCoordinate.first];
			minX = givenCoordinate.first;
			minY = givenCoordinate.second + 1;
		}
	}
	if (isValidPosition(walkMap, givenCoordinate.first, givenCoordinate.second - 1)) { // top
		if (map[givenCoordinate.second - 1][givenCoordinate.first] < minVal && map[givenCoordinate.second - 1][givenCoordinate.first] != 0) {
			minVal = map[givenCoordinate.second - 1][givenCoordinate.first];
			minX = givenCoordinate.first;
			minY = givenCoordinate.second - 1;
		}
	}

	result.first = minX;
	result.second = minY;
}