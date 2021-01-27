#pragma once
#include "EngineConstants.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <stdio.h>
#include "Game.h"

const EngineConstants e_constants;

class GameEngine {
	private:

		SDL_Renderer* renderer = NULL;
		SDL_Window* window = NULL;
		SDL_Surface* screenSurface = NULL;
		std::vector<SDL_Texture*> spriteTextures;

		Game Digger;

		unsigned short screenWidth, screenHeight;
		bool gameRunning;
		unsigned frameRate;

		void engineUpdate();	// engine update
		void update();			// game logic update
		void render();			// displays images
		void input();			// keyboard input
		void preload();			// preloads assets for the game
		unsigned timeLeft(const unsigned& nextTime);

		bool createWindow(const unsigned short& width, const unsigned short& height);
		bool createRenderer();
		void exit();


	public:
		GameEngine();
		~GameEngine();

		GameEngine(const GameEngine& other) = delete;
		GameEngine& operator = (const GameEngine& other) = delete;

		void run();
};