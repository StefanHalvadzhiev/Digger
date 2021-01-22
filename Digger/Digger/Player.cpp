#include "Player.h"

Player::Player() {
	ammo = true;
	lives = player_constants.playerLives;
	x = 0;
	y = 0;
}

Player::~Player() {

}

const unsigned& Player::getX() {
	return x;
}

const unsigned& Player::getY() {
	return y;
}

