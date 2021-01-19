#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game {
	private:
		Player player;
		std::vector<Enemy> enemies;


	public:
		Game();
		~Game();

		Game& operator = (const Game& other) = delete;
		Game(const Game& other) = delete;
		
		void tracePlayer();

};