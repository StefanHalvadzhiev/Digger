#pragma once
#include "GameConstants.h"
static const GameConstants g_constants;

#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstring>


class Game {
	private:
		typedef std::vector<std::vector<bool>> GameMap;

		Player player;
		unsigned maxEnemyCount, currentEnemyCount;
		unsigned currentLevel;
		std::vector<Enemy> enemies;

		GameMap walkableMap;
		
	public:
		Game();
		~Game();

		Game& operator = (const Game& other) = delete;
		Game(const Game& other) = delete;
		
		void tracePlayer(bool recalculateWholeRoute);
		void loadNextLevel();

		Player* getPlayer();
};