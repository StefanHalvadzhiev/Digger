#include "Player.h"

Player::Player() {
	ammo = true;
	lives = player_constants.playerLives;
	x = 0;
	y = 0;
	mapBorderX = 0;
	mapBorderY = 0;
	spawnX = 0;
	spawnY = 0;
}

Player::~Player() {

}

const unsigned short& Player::getCX() {
	return x;
}

const unsigned short& Player::getCY() {
	return y;
}

unsigned short Player::getX() {
	return x;
}

unsigned short Player::getY() {
	return y;
}

void Player::setPosition(const unsigned short positionX, const unsigned short positionY) {
	x = positionX;
	y = positionY;
}

bool Player::walkDown() {
	if (y + 1 >= mapBorderY)
		return false;
	y++;
	return true;	 
}

bool Player::walkUp() {
	if (!y)
		return false;
	y--;
	return true;

}

bool Player::walkRight() {
	if (x + 1 >= mapBorderX)
		return false;
	x++;
	return true;
}

bool Player::walkLeft() {
	if (!x)
		return false;
	x--;
	return true;
}

void Player::setMapBorder(const unsigned short mx, const unsigned short my) {
	mapBorderX = mx;
	mapBorderY = my;
}

void Player::setSpawnPoint(const unsigned short sx, const unsigned short sy) {
	spawnX = sx;
	spawnY = sy;
}