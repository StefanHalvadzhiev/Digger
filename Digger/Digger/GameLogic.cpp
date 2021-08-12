#include "GameEngine.h"
#include "Texture.h"

void GameEngine::update(unsigned time) { // 60 times per second
	if (!Digger.getGameOver()) {
		Digger.updateGameTime(time);
		Digger.updateEnemyTime(time);
		Digger.spawnEnemy();
		Digger.tracePlayer(true);
		Digger.handleEnemyPlayerCollision();
		Digger.moveEnemies();
	}
	else
		exit();
	
}

void GameEngine::render() { // 60 times per second
	SDL_RenderClear(renderer);
	Digger.drawMap();
  	Digger.drawScore();
	Digger.drawLives();
	SDL_RenderPresent(renderer);
}

void GameEngine::input() { // 60 times per second
	if (keyboard[SDLK_ESCAPE])
		exit();
	if (!Digger.isPaused()) {
		if (keyboard[SDLK_w])
			Digger.movePlayerUp();
		if (keyboard[SDLK_s])
			Digger.movePlayerDown();
		if (keyboard[SDLK_a])
			Digger.movePlayerLeft();
		if (keyboard[SDLK_d])
			Digger.movePlayerRight();
	}
}

void GameEngine::preload() { // loads the initial information for the game
	Digger.setRenderer(renderer);
	Digger.setLives(renderer);
	if (!Digger.loadNextLevel())
		exit();
}
