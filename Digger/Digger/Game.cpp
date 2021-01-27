#include"Game.h"

Game::Game() {
	currentLevel = 0;
	maxEnemyCount = g_constants.maxEnemyCount;
	currentEnemyCount = 0;
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

		unsigned short currentCell;
		for (unsigned i = 0; i < levelWidth; ++i){
			std::vector<bool> cellRow;
			walkableMap.push_back(cellRow);
			for (unsigned z = 0; z < levelHeight; ++z) {
				level >> currentCell;
				walkableMap[i].push_back(currentCell);
			}
		}
	}
	else {
		printf("Error loading level.");
	}
}

Player* Game::getPlayer() {
	return &player;
}