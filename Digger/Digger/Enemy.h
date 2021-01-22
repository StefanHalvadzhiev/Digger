#pragma once
#include <queue>
#include <vector>
typedef std::vector<std::vector<bool>>  GameMap;
typedef std::queue<std::pair<unsigned int, unsigned int>> tracePath;

class Enemy {
	private:
		unsigned x, y;
		bool alive;
		tracePath path ;
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy& other) = delete;
		Enemy& operator = (const Enemy& other) = delete;


		void AStarTrace(const GameMap& walkMap, bool recalculate, const unsigned& pX, const unsigned& pY);
};