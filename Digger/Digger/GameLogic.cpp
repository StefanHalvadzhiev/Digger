#include "GameEngine.h"
#include "Texture.h"

void GameEngine::update() { // 60 times per second


}

void GameEngine::render() { // 60 times per second
	SDL_RenderClear(renderer);
	Digger.drawMap();
	SDL_RenderPresent(renderer);
}

void GameEngine::input() { // 60 times per second
	if (keyboard[SDLK_ESCAPE])
		exit();
}

void GameEngine::preload() { // loads the initial information for the game
	Digger.setRenderer(renderer);
	Digger.loadNextLevel();
}

