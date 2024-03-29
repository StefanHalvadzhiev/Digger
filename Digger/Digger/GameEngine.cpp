#include"GameEngine.h"

GameEngine::GameEngine() {
	gameRunning = true;
	screenWidth = e_constants.screenWidth;
	screenHeight = e_constants.screenHeight;
	frameRate = e_constants.frameRate;
	tickInterval = 1000 / frameRate;
	SDL_Init(SDL_INIT_EVERYTHING);
}

GameEngine::~GameEngine() {
	if (window)
		SDL_DestroyWindow(window);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool GameEngine::createWindow(const unsigned short& width, const unsigned short& height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		window = SDL_CreateWindow("Digger", e_constants.winPosX, e_constants.winPosY, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL) {
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
	unsigned nextTime = SDL_GetTicks() + tickInterval;
	while (gameRunning) {
		handleSDLEvents();
		if (!Digger.isPaused()) {
			render();
			update(tickInterval);
			input();
		}

		SDL_Delay(timeLeft(nextTime));
		nextTime += tickInterval;
	}
}

bool GameEngine::createRenderer() {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer)
		return true;
	return false;
}

void GameEngine::run() {
	if (createWindow(screenWidth, screenHeight) && createRenderer()) {
		preload();
		engineUpdate();
	}
	else
		printf("Game could not start. Please try again.");
}

void GameEngine::exit() {
	gameRunning = false;
}

void GameEngine::initKeyInput() {
	for (unsigned i = 0; i < 322; ++i)
		keyboard[i] = false;
}

void GameEngine::handleSDLEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym >= 322)
				break;
			keyboard[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym >= 322)
				break;
			keyboard[event.key.keysym.sym] = false;
			break;
		default:
			break;
		}
		switch (event.window.event) {
		case SDL_WINDOWEVENT_MINIMIZED:
			Digger.Pause(true);
			break;
		case SDL_WINDOWEVENT_RESTORED:
			Digger.Pause(false);
			break;
		}
	}
}