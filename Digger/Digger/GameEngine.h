#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Game.h"

class GameEngine {
	private:
		SDL_Window* window = NULL;
		SDL_Surface* screenSurface = NULL;

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
		void exit();

		
	public:
		GameEngine();
		~GameEngine();

		GameEngine(const GameEngine& other) = delete;
		GameEngine& operator = (const GameEngine& other) = delete;

		void run();
};