#pragma once
#include "Texture.h"
#include "Enemy.h"

class LevelBlock {
	private:
		int positionX, positionY; // display position
		int realX, realY; // logic position
		bool isSolid;
		bool hasPlayer;
		bool hasCoin;
		bool hasBagOfCoins;
		bool hasGem;
		bool hasEnemy;

	public:
		InGameTexture levelTexture;
		InGameTexture gemTexture;
		InGameTexture coinTexture;
		InGameTexture bagOfCoinsTexture;
		InGameTexture enemyTexture;
		InGameTexture playerTexture;

		void setPlayer(const bool type);
		void setSolid(const bool type);
		void setCoin(const bool type);
		void setBagOfCoins(const bool type);
		void setGem(const bool type);
		void setEnemy(const bool type);


		bool isGemAvailable();


		void draw();
		void setInitialCondition(const unsigned short type);
		void passRenderToTextures(SDL_Renderer*& renderer);
		LevelBlock() = default;
		LevelBlock(const int positionX, const int positionY, SDL_Renderer*& renderer);
		~LevelBlock() = default;
};