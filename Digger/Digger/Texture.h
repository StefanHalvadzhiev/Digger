#pragma once
#include <SDL_image.h>
#include <SDL.h>

class InGameTexture {
	private:
		SDL_Texture* image = NULL;
		SDL_Rect texture;
		SDL_Renderer* renderer = NULL;
		float scaleX, scaleY;
		int width, height;
		void copy(const InGameTexture& other);
	public:		
		void setRenderer(SDL_Renderer*& renderer);
		InGameTexture();
		InGameTexture(const InGameTexture& other);
		InGameTexture& operator =(const InGameTexture& other);
		void setImageTexture(const char* path);
		void setScale(const float x, const float y);
		void setCoordinates(const int x, const int y);

		void draw();

		int getX();
		int getY();
		int getWidth();
		int getHeight();
		int getImageHeight();
		int getImageWidth();
		unsigned getScaleX();
		unsigned getScaleY();
};	