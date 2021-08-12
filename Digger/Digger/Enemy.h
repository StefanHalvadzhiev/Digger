#pragma once
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include "Texture.h"
#include "GameConstants.h"

const GameConstants enemyConstants;


class Enemy {
	private:
		typedef std::vector<std::vector<bool>>  GameMap;
		typedef std::deque<std::pair<unsigned short, unsigned short>> tracePath;
		typedef std::pair<unsigned short, unsigned short> Coordinate;
		typedef std::vector<std::vector<unsigned>> AdjecencyMap;
		typedef const unsigned short cus;


		unsigned short x, y;
		unsigned short prevX, prevY;
		unsigned short mapWidth, mapHeight;
		tracePath path ;

		unsigned moveTime;
		unsigned currentTime;


		void copy(const Enemy& other);
		bool isValidPosition(const GameMap& walkMap, cus& pX, cus& pY);
		void findPath(const GameMap& walkMap, cus& pX, cus& pY);
		bool isPassable(const GameMap& walkMap, cus& pX, cus& pY);
		bool hasFoundPlayerCell(cus& pX, cus& pY, cus& eX, cus& eY);
		void getMinimalPosition(Coordinate& givenCoordinate, Coordinate& result,const AdjecencyMap& map, const GameMap& walkMap);
	public:

		Enemy();
		Enemy(cus x, cus y);
		~Enemy() = default;
		Enemy(const Enemy& other);
		Enemy& operator = (const Enemy& other);

		void tracePathToPlayer(const GameMap& walkMap, const bool recalculate, cus& pX, cus& pY);

		void setInitialPosition(cus x, cus y);
		void setPosition(cus x, cus y);
		void setBoundaries(cus width, cus height);
		void move();

		unsigned short getPrevX();
		unsigned short getPrevY();
		unsigned short getX();
		unsigned short getY();

		void updateTime(unsigned newTime);
};