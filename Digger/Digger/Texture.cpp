#include "Texture.h"
#include <iostream>

InGameTexture::InGameTexture() {
	scaleX = 1;
	scaleY = 1;
	texture.x = 0;
	texture.y = 0;
}

void InGameTexture::copy(const InGameTexture& other) {
	this->image = other.image;
	this->texture = other.texture;
	this->renderer = other.renderer;
	this->scaleX = other.scaleX;
	this->scaleY = other.scaleY;
	this->width = other.width;
	this->height = other.height;
}

InGameTexture::InGameTexture(const InGameTexture& other) {
	copy(other);
}

InGameTexture& InGameTexture::operator=(const InGameTexture& other) {
	if (this != &other)
		copy(other);
	return *this;
}

void InGameTexture::setImageTexture(const char* path) {
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

void InGameTexture::draw() {
	if (renderer == NULL)
		std::cout << "No renderer" << std::endl;
	SDL_RenderCopy(renderer, image, NULL, &texture);
}

void InGameTexture::setCoordinates(const int x, const int y) {
	texture.x = x;
	texture.y = y;
}


void InGameTexture::setRenderer(SDL_Renderer*& renderer) {
	this->renderer = renderer;
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