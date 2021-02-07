#include"Game.h"

Game::Game() {
	currentLevel = 0;
	maxEnemyCount = g_constants.maxEnemyCount;
	currentEnemyCount = 0;
	timeSinceLastEnemySpawn = 0;
	levelWidth = 0;
	levelHeight = 0;
	enemySpawnX = 0;
	enemySpawnY = 0;
	renderer = NULL;
	paused = false;
}

void Game::tracePlayer(bool recalculateWholeRoute) {
	for (std::list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it)
		it->tracePathToPlayer(walkableMap, true, player.getX(), player.getY());
}

void Game::loadNextLevel() {
	currentLevel++;
	std::ifstream level;
	char buffer[33];
	char levelName[50] = "Levels/";
	strcat(levelName, _itoa(currentLevel, buffer, 10));
	strcat(levelName, ".txt");
	level.open(levelName);
	if (level.is_open()) {
		level >> levelWidth >> levelHeight;
		player.setMapBorder(levelWidth, levelHeight);
		unsigned short currentCell;
		for (unsigned i = 0; i < levelHeight; ++i){
			std::vector<bool> cellRow;
			std::vector<LevelBlock> levelBlocks;
			walkableMap.push_back(cellRow);
			gameMap.push_back(levelBlocks);
			for (unsigned z = 0; z < levelWidth; ++z) {
				level >> currentCell;
				
				LevelBlock buffer(z * 64, (i + 1) * 64, renderer);
				buffer.setInitialCondition(currentCell);
				gameMap[i].push_back(buffer);
				walkableMap[i].push_back(currentCell);

				if (currentCell == 4) {
					player.setPosition(z, i);
					player.setSpawnPoint(z, i);
					walkableMap[i][z] = false;

				}
				if (currentCell == 5) {
					enemySpawnX = z;
					enemySpawnY = i;
					walkableMap[i][z] = false;


				}

			}
		}
		level.close();
	}
	else {
		printf("Error loading level.");
	}
}

Player* Game::getPlayer() {
	return &player;
}


void Game::setRenderer(SDL_Renderer*& renderer) {
	this->renderer = renderer;
	score.init(renderer);
}

void Game::drawMap() {
	updateDrawMapEnemyPositions();
	for (unsigned i = 0; i < gameMap.size(); ++i) {
		for (unsigned p = 0; p < gameMap[i].size(); ++p) {
			gameMap[i][p].draw();
		}
	}
}

void Game::Pause(bool state) {
	paused = state;
}

bool Game::isPaused() {
	return paused;
}

void Game::movePlayerUp() {
	unsigned short oldX = player.getX();
	unsigned short oldY = player.getY();

	if (player.walkUp()) {
		unsigned short newX = player.getX();
		unsigned short newY = player.getY();
		walkableMap[newY][newX] = false;
		gameMap[newY][newX].setSolid(false);
		gameMap[newY][newX].setPlayer(true);
		gameMap[oldY][oldX].setPlayer(false);
	}
	checkIfGemIsTaken();
}

void Game::movePlayerDown() {
	unsigned short oldX = player.getX();
	unsigned short oldY = player.getY();

	if (player.walkDown()) {
		unsigned short newX = player.getX();
		unsigned short newY = player.getY();
walkableMap[newY][newX] = false;
gameMap[newY][newX].setSolid(false);
gameMap[newY][newX].setPlayer(true);
gameMap[oldY][oldX].setPlayer(false);

	}
	checkIfGemIsTaken();
}

void Game::movePlayerLeft() {
	unsigned short oldX = player.getX();
	unsigned short oldY = player.getY();

	if (player.walkLeft()) {
		unsigned short newX = player.getX();
		unsigned short newY = player.getY();
		walkableMap[newY][newX] = false;
		gameMap[newY][newX].setSolid(false);
		gameMap[newY][newX].setPlayer(true);
		gameMap[oldY][oldX].setPlayer(false);
	}
	checkIfGemIsTaken();
}

void Game::movePlayerRight() {
	unsigned short oldX = player.getX();
	unsigned short oldY = player.getY();

	if (player.walkRight()) {
		unsigned short newX = player.getX();
		unsigned short newY = player.getY();
		walkableMap[newY][newX] = false;
		gameMap[newY][newX].setSolid(false);
		gameMap[newY][newX].setPlayer(true);
		gameMap[oldY][oldX].setPlayer(false);
	}
	checkIfGemIsTaken();
}


void Game::updateGameTime(unsigned time) {
	timeSinceLastEnemySpawn += time;
}

void Game::spawnEnemy() {
	if (timeSinceLastEnemySpawn >= g_constants.spawnDelay && currentEnemyCount < maxEnemyCount) {
		innerSpawnEnemy();
		timeSinceLastEnemySpawn = 0;
		currentEnemyCount++;
	}
}

void Game::innerSpawnEnemy() {
	Enemy newEnemy;
	newEnemy.setInitialPosition(enemySpawnX, enemySpawnY);
	newEnemy.setBoundaries(levelWidth, levelHeight);
	enemies.push_back(newEnemy);
}

void Game::moveEnemies() {
	for (std::list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it)
		it->move();
}

void Game::updateDrawMapEnemyPositions() {
	for (std::list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		gameMap[it->getPrevY()][it->getPrevX()].setEnemy(false);
		gameMap[it->getY()][it->getX()].setEnemy(true);
	}
}

void Game::checkIfGemIsTaken() {
	if (gameMap[player.getY()][player.getX()].isGemAvailable()) {
		gameMap[player.getY()][player.getX()].setGem(false);
		score.addScore(g_constants.gemScore);
	}
}

void Game::drawScore() {
	score.draw();
}

void Game::setLives(SDL_Renderer*& renderer) {
	for (unsigned i = 0; i < g_constants.playerLives; ++i) {
		InGameTexture life;
		life.setRenderer(renderer);
		life.setImageTexture("images/player.png");
		life.setCoordinates(g_constants.lifeStartX - i * g_constants.lifeHorizontalSpacing, g_constants.lifeStartY);
		life.setScale(1, 1);
		lives.push_back(life);
	}
}

void Game::drawLives() {

	for (unsigned i = 0; i < player.getLives(); ++i) {
		lives[i].draw();
	}
}

void Game::handleEnemyPlayerCollision() {
	for(std::list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it){
		if (it->getX() == player.getX() && it->getY() == player.getY() || it->getPrevX() == player.getX() && it->getPrevY() == player.getY()) {
			gameMap[player.getY()][player.getX()].setPlayer(false);
			player.moveToSpawn();
			gameMap[player.getY()][player.getX()].setPlayer(true);
			while (!enemies.empty()) {
				gameMap[enemies.front().getY()][enemies.front().getX()].setEnemy(false);
				enemies.pop_front();
			}
			if (player.getLives())
				player.reduceLives();
			else
				gameOver = true;
			currentEnemyCount = 0;
			break;
		}

	}
}

bool Game::getGameOver() {
	return gameOver;
}