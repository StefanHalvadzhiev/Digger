#pragma once
#include "GameConstants.h"
static const GameConstants g_constants;

#include "Player.h"
#include "Enemy.h"
#include "LevelBlock.h"
#include "Score.h"
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
	typedef std::vector<InGameTexture> PlayerLives;

	bool paused;
	SDL_Renderer* renderer;
	Player player;

	unsigned maxEnemyCount, currentEnemyCount;
	unsigned short enemySpawnX, enemySpawnY;
	std::list<Enemy> enemies;
	unsigned timeSinceLastEnemySpawn;

	unsigned currentLevel;

	PlayerLives lives;

	LogicMap walkableMap;
	GameMap gameMap;
	unsigned short levelWidth, levelHeight;

	Score score;

	bool gameOver = false;
	void innerSpawnEnemy();
	void updateDrawMapEnemyPositions();
public:
	Game();
	~Game() = default;

	Game& operator = (const Game& other) = delete;
	Game(const Game& other) = delete;

	void tracePlayer(bool recalculateWholeRoute);
	bool loadNextLevel();
	void setRenderer(SDL_Renderer*& renderer);
	void drawMap();
	void Pause(bool pause);
	bool isPaused();

	void checkIfGemIsTaken();
	void movePlayerUp();
	void movePlayerDown();
	void movePlayerLeft();
	void movePlayerRight();
	Player* getPlayer();

	void updateGameTime(unsigned time);
	void updateEnemyTime(unsigned time);

	void spawnEnemy();
	void moveEnemies();

	void setLives(SDL_Renderer*& renderer);
	void drawScore();
	void drawLives();

	void handleEnemyPlayerCollision();
	bool getGameOver();
};