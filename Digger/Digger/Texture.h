#pragma once
#include <SDL_image.h>
#include <SDL.h>

class InGameTexture {
	private:
		SDL_Texture* image = NULL;
		SDL_Rect texture;

		float scaleX, scaleY;
		int width, height;
	public:
		InGameTexture();

		void setImageTexture(const char* path, SDL_Renderer*& renderer);
		void setScale(const float x, const float y);
		void setCoordinates(const int x, const int y);

		void draw(SDL_Renderer*& renderer);

		int getX();
		int getY();
		int getWidth();
		int getHeight();
		int getImageHeight();
		int getImageWidth();
		unsigned getScaleX();
		unsigned getScaleY();
};