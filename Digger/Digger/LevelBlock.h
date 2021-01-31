#pragma once
#include "Texture.h"
#include "Enemy.h"
#include <list>

class LevelBlock {
	private:
		int positionX, positionY;
		bool isSolid;
		bool hasPlayer;
		bool hasCoin;
		bool hasGold;
		bool hasGem;
		std::list<Enemy*> enemies;
	public:
		InGameTexture levelTexture;
		InGameTexture gemTexture;
		InGameTexture coinTexture;
		InGameTexture goldTexture;
		InGameTexture enemyTexture;
		InGameTexture playerTexture;

		void draw();
		void setInitialCondition(const unsigned short type);
		void passRenderToTextures(SDL_Renderer*& renderer);
		LevelBlock() = default;
		LevelBlock(const int positionX, const int positionY, SDL_Renderer*& renderer);
		~LevelBlock() = default;
};