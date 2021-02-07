#pragma once
#include "GameConstants.h"
#include "Texture.h"
static const GameConstants player_constants;


class Player {
	private:
		unsigned short spawnX, spawnY;				// spawn position
		unsigned short x, y;						// current position
		unsigned short mapBorderX, mapBorderY;		// edge of the map
		unsigned lives;
		bool ammo;

	public:

		Player();
		Player(const Player& other) = delete;
		Player& operator = (const Player& other) = delete;


		void setPosition(const unsigned short positionX, const unsigned short positionY);
		void moveToSpawn();
		void setSpawnPoint(const unsigned short sx, const unsigned short sy);
		const unsigned short& getCX();
		const unsigned short& getCY();
		unsigned short getX();
		unsigned short getY();

		bool walkLeft();
		bool walkRight();
		bool walkUp();
		bool walkDown();

		void setMapBorder(const unsigned short mx, const unsigned short my);

		void reduceLives();
		unsigned int getLives();
};