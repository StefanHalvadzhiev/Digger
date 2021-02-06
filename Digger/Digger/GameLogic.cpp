#include "GameEngine.h"
#include "Texture.h"

void GameEngine::update(unsigned time) { // 60 times per second
	Digger.updateGameTime(time);
	Digger.spawnEnemy();
	Digger.tracePlayer(true);
	Digger.moveEnemies();
}

void GameEngine::render() { // 60 times per second
	SDL_RenderClear(renderer);
	Digger.drawMap();
	SDL_RenderPresent(renderer);
}

void GameEngine::input() { // 60 times per second
	if (keyboard[SDLK_ESCAPE])
		exit();
	if (keyboard[SDLK_w]) 
		Digger.movePlayerUp();
	if (keyboard[SDLK_s])
		Digger.movePlayerDown();
	if (keyboard[SDLK_a])
		Digger.movePlayerLeft();
	if (keyboard[SDLK_d])
		Digger.movePlayerRight();

	
}

void GameEngine::preload() { // loads the initial information for the game
	Digger.setRenderer(renderer);
	Digger.loadNextLevel();
}

