#pragma once
#include <queue>
#include <vector>
typedef std::vector<std::vector<bool>>  GameMap;

class Enemy {
	private:
		unsigned x, y;
		bool alive;
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy& other) = delete;
		Enemy& operator = (const Enemy& other) = delete;


		void AStarTrace(const GameMap& walkMap, bool recalculate, const unsigned& pX, const unsigned& pY);
};