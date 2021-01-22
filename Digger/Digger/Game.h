#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
typedef std::vector<std::vector<bool>> GameMap;


class Game {
	private:
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
		void spawnEnemy();
};