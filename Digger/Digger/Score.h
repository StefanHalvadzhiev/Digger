#pragma once
#include "Texture.h"
#include "GameConstants.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

const GameConstants score_constants;

class Score {
private:
	typedef std::vector<std::vector<InGameTexture>> Digits;
	unsigned score;
	unsigned x, y;
	unsigned spacingX;
	unsigned spacingY;
	unsigned short digitCount;
	Digits digits;
public:
	Score();
	void draw();
	void addScore(unsigned points);
	void init(SDL_Renderer*& renderer);
	void resizeScore();
};