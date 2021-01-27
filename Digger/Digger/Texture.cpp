#include "Texture.h"

InGameTexture::InGameTexture() {
	scaleX = 1;
	scaleY = 1;
	texture.x = 0;
	texture.y = 0;
}

void InGameTexture::setImageTexture(const char* path, SDL_Renderer*& renderer) {
	image = IMG_LoadTexture(renderer, path);
	SDL_QueryTexture(image, NULL, NULL, &width, &height);
	texture.w = width;
	texture.h = height;
}

void InGameTexture::setScale(const float x, const float y) {
	scaleX = x;
	scaleY = y;
	texture.w = width * scaleX;
	texture.h = height * scaleY;
}

void InGameTexture::draw(SDL_Renderer*& renderer) {
	SDL_RenderCopy(renderer, image, NULL, &texture);
}

void InGameTexture::setCoordinates(const int x, const int y) {
	texture.x = x;
	texture.y = y;
}

int InGameTexture::getX() {
	return texture.x;
}
int InGameTexture::getY() {
	return texture.y;
}

int InGameTexture::getWidth() {
	return texture.w;
}

int InGameTexture::getHeight() {
	return texture.h;
}

int InGameTexture::getImageHeight() {
	return height;
}

int InGameTexture::getImageWidth() {
	return width;
}

unsigned InGameTexture::getScaleX() {
	return scaleX;
}

unsigned InGameTexture::getScaleY() {
	return scaleY;
}