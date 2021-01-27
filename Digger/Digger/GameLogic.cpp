#include "GameEngine.h"
#include "Texture.h"

void GameEngine::update() { // 60 times per second


}

void GameEngine::render() { // 60 times per second
	SDL_RenderClear(renderer);
	Digger.getPlayer()->playerModel.draw(renderer);
	SDL_RenderPresent(renderer);
}

void GameEngine::input() { // 60 times per second

}

void GameEngine::preload() { // loads the initial information for the game
	Digger.loadNextLevel();
	Digger.getPlayer()->playerModel.setImageTexture("images/player.png", renderer);

}


