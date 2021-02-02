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
#include "LevelBlock.h"

class Game {
	private:
		typedef std::vector<std::vector<bool>> LogicMap;
		typedef std::vector<std::vector<LevelBlock>> GameMap;	
		bool paused;
		SDL_Renderer* renderer;
		Player player;
		unsigned maxEnemyCount, currentEnemyCount;
		unsigned currentLevel;
		std::vector<Enemy> enemies;

		LogicMap walkableMap;
		GameMap gameMap;
		
	public:
		Game();
		~Game();

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
};