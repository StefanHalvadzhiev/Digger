#include"GameEngine.h"
#define csr = const short
#define csuir = const unsigned int

GameEngine::GameEngine() {
	gameRunning = true;
	screenWidth = 1366;
	screenHeight = 768;
	frameRate = 2;
}

GameEngine::~GameEngine() {
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();

}

bool GameEngine::createWindow(const unsigned short& width, const unsigned short& height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else{
		window = SDL_CreateWindow("Digger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL){
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else
			screenSurface = SDL_GetWindowSurface(window);
	}
	return true;
}

unsigned GameEngine::timeLeft(const unsigned& nextTime) {
	unsigned now;

	now = SDL_GetTicks();
	if (nextTime <= now)
		return 0;
	else
		return nextTime - now;
}

void GameEngine::engineUpdate() {
	unsigned tickInterval = 1000 / frameRate;
	unsigned nextTime = SDL_GetTicks() + tickInterval;
	while (gameRunning) {
		update();

		SDL_Delay(timeLeft(nextTime));
		nextTime += tickInterval;
	}
}

void GameEngine::update() {
	//insert game logic here
}

void GameEngine::render() {

}

void GameEngine::run() {
	if (createWindow(screenWidth, screenHeight))
		engineUpdate();
	else
		printf("Game could not start. Please try again.");
}

void GameEngine::exit() {
	gameRunning = false;
}