#pragma once
#include "GameConstants.h"
#include "Texture.h"
static const GameConstants player_constants;


class Player {
	private:
		unsigned x, y;
		unsigned lives;
		bool ammo;

	public:
		InGameTexture playerModel;

		Player();
		~Player();
		Player(const Player& other) = delete;
		Player& operator = (const Player& other) = delete;

		const unsigned& getX();
		const unsigned& getY();

};