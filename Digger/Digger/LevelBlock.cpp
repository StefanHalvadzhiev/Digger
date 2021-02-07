#include "LevelBlock.h"
#include <iostream>
LevelBlock::LevelBlock(const int positionX, const int positionY, SDL_Renderer*& renderer) {
	this->positionX = positionX;
	this->positionY = positionY;
	passRenderToTextures(renderer);
 	levelTexture.setImageTexture("images/block.png");
	gemTexture.setImageTexture("images/gem.png");
	coinTexture.setImageTexture("images/coin.png");
	enemyTexture.setImageTexture("images/enemy.png");
	bagOfCoinsTexture.setImageTexture("images/bag_of_coins.png");
	playerTexture.setImageTexture("images/player.png");

	levelTexture.setCoordinates(positionX, positionY);
	gemTexture.setCoordinates(positionX, positionY);
	coinTexture.setCoordinates(positionX, positionY);
	enemyTexture.setCoordinates(positionX, positionY);
	bagOfCoinsTexture.setCoordinates(positionX, positionY);
	playerTexture.setCoordinates(positionX, positionY);

	levelTexture.setScale(1, 1);
	gemTexture.setScale(1, 1);
	coinTexture.setScale(1, 1);
	enemyTexture.setScale(1, 1);
	bagOfCoinsTexture.setScale(1, 1);
	playerTexture.setScale(1, 1);

	isSolid = false;
	hasBagOfCoins = false;
	hasCoin = false;
	hasGem = false;
	hasPlayer = false;
	hasEnemy = false;
}

void LevelBlock::draw() {
	if (isSolid)
		levelTexture.draw();
	if (hasGem)
		gemTexture.draw();
	if (hasBagOfCoins)
		bagOfCoinsTexture.draw();
	if (hasCoin)
		coinTexture.draw();
	if (hasEnemy)
		enemyTexture.draw();
	if (hasPlayer) 
		playerTexture.draw();
}

void LevelBlock::setInitialCondition(const unsigned short type) {
	// 0 = empty cell
	// 1 = wall only
	// 2 = wall + gem
	// 3 = wall + coin bag
	// 4 = player spawn position.
	// 5 = enemy spawn position. 
	if (type == 1) {
		isSolid = true;
	}
	if (type == 2) {
		isSolid = true;
		hasGem = true;

	}
	if (type == 3){
		isSolid = true;
		hasBagOfCoins = true;
	}
	if (type == 4){
		hasPlayer = true;
	}
}


void LevelBlock::passRenderToTextures(SDL_Renderer*& renderer) {
	levelTexture.setRenderer(renderer);
	gemTexture.setRenderer(renderer);
	coinTexture.setRenderer(renderer);
	bagOfCoinsTexture.setRenderer(renderer);
	enemyTexture.setRenderer(renderer);
	playerTexture.setRenderer(renderer);
}

void LevelBlock::setPlayer(const bool type) {
	hasPlayer = type;
}

void LevelBlock::setSolid(const bool type) {
	isSolid = type;
}

void LevelBlock::setCoin(const bool type) {
	hasCoin = type;
}

void LevelBlock::setBagOfCoins(const bool type) {
	hasBagOfCoins = type;
}

void LevelBlock::setGem(const bool type) {
	hasGem = type;
}

void LevelBlock::setEnemy(const bool type) {
	hasEnemy = type;
}

bool LevelBlock::isGemAvailable() {
	return hasGem;
}