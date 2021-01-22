#include"Game.h"
#include <fstream>

Game::Game() {
	currentLevel = 0;
	maxEnemyCount = 0;
	currentEnemyCount = 0;
}

Game::~Game() {


}

void Game::tracePlayer(bool recalculateWholeRoute) {
	for (unsigned i = 0; i < enemies.size(); ++i) 
		enemies[i].AStarTrace(walkableMap, recalculateWholeRoute, player.getX(), player.getY());
}

void Game::loadNextLevel() {

}