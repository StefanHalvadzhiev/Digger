#include"Game.h"

Game::Game() {
	currentLevel = 0;
	maxEnemyCount = g_constants.maxEnemyCount;
	currentEnemyCount = 0;
	renderer = NULL;
	paused = false;
}

Game::~Game() {


}

void Game::tracePlayer(bool recalculateWholeRoute) {
	for (unsigned i = 0; i < enemies.size(); ++i) 
		enemies[i].AStarTrace(walkableMap, recalculateWholeRoute, player.getX(), player.getY());
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
		unsigned levelWidth, levelHeight;
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
				if (currentCell == 4) {
					player.setPosition(z, i);
					player.setSpawnPoint(z, i);
				}
				LevelBlock buffer(z * 64, (i + 1) * 64, renderer);
				buffer.setInitialCondition(currentCell);
				gameMap[i].push_back(buffer);
				walkableMap[i].push_back(currentCell);
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
}

void Game::drawMap() {
	for (unsigned i = 0; i < gameMap.size(); ++i) {
		for (unsigned p = 0; p < gameMap[i].size(); ++p) {
			gameMap[i][p].draw();
		}
	}
}

void Game::Pause(bool pause) {
	paused = pause;
	if (pause)
		std::cout << "Paused." << std::endl;
	else
		std::cout << "Resumed." << std::endl;
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
		std::cout << "Walked Up" << std::endl;
	}
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
		std::cout << "Walked Down" << std::endl;

	}
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
		std::cout << "Walked Left" << std::endl;
	}
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
		std::cout << "Walked Right" << std::endl;
	}
}