#include "Score.h"
#include <cstring>
#include <iostream>

Score::Score() {
	score = 0;
	x = score_constants.scoreStartX;
	y = score_constants.scoreStartY;
	spacingX = score_constants.scoreSpacingX;
	spacingY = score_constants.scoreSpacingY;
	digitCount = score_constants.scoreDigitCount;
}

void Score::init(SDL_Renderer*& renderer) {
	char path[13] = "images/0.png";
	for (unsigned short i = 0; i < digitCount; ++i) {
		std::vector<InGameTexture> digitRow;
		for (unsigned p = 0; p < 10; ++p) {
			path[7] = 48 + p;
			InGameTexture newDigit;
			newDigit.setRenderer(renderer);
			newDigit.setImageTexture(path);
			newDigit.setCoordinates(x + spacingX * i, y + spacingY * i);
			digitRow.push_back(newDigit);
		}
		digits.push_back(digitRow);
	}
}

void Score::addScore(unsigned points) {
	score += points;
}

void Score::draw() {
	if (score > 999999)
		resizeScore();
	unsigned buffer = score;
	for (unsigned i = 0; i < digitCount; ++i) {
		digits[digitCount - 1 - i][buffer % 10].draw();
		buffer /= 10;
	}
}

void Score::resizeScore() {
}