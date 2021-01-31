#pragma once
#include "GameConstants.h"
#include "Texture.h"
static const GameConstants player_constants;


class Player {
	private:
		unsigned short x, y;
		unsigned lives;
		bool ammo;

	public:

		Player();
		~Player();
		Player(const Player& other) = delete;
		Player& operator = (const Player& other) = delete;


		void setPosition(const unsigned short positionX, const unsigned short positionY);
		const unsigned& getX();
		const unsigned& getY();

};