#pragma once
#include "GameConstants.h"
static const GameConstants g_constants;

#include "Player.h"
#include "Enemy.h"
#include "LevelBlock.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <cstring>

class Game {
	private:
		typedef std::vector<std::vector<bool>> LogicMap;
		typedef std::vector<std::vector<LevelBlock>> GameMap;	

		bool paused;
		SDL_Renderer* renderer;
		Player player;

		unsigned maxEnemyCount, currentEnemyCount;
		unsigned short enemySpawnX, enemySpawnY;
		std::list<Enemy> enemies;
		unsigned timeSinceLastEnemySpawn;

		unsigned currentLevel;
		

		LogicMap walkableMap;
		GameMap gameMap;
		unsigned short levelWidth, levelHeight;

		void innerSpawnEnemy();
		void updateDrawMapEnemyPositions();
	public:
		Game();
		~Game() = default;

		Game& operator = (const Game& other) = delete;
		Game(const Game& other) = delete;
		
		void tracePlayer(bool recalculateWholeRoute);
		void loadNextLevel();
		void setRenderer(SDL_Renderer*& renderer);
		Player* getPlayer();
		void drawMap();
		void Pause(bool pause);
		bool isPaused();

		void movePlayerUp();
		void movePlayerDown();
		void movePlayerLeft();
		void movePlayerRight();

		void updateGameTime(unsigned time);

		void spawnEnemy();
		void moveEnemies();

};