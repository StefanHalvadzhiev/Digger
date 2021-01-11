#include <SDL.h>
#include "GameEngine.h"
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int frameRate = 2;

int main(int argc, char* args[]){	
	GameEngine Digger;
	Digger.run();
	return 0;
}