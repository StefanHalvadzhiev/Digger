#pragma once
const struct GameConstants {
	typedef unsigned int uint;
	
	uint playerLives = 3;
	uint maxEnemyCount = 2;
	uint spawnDelay = 1000; // 1000 = 1s 

	uint scoreSpacingX = 40; // 40 px;
	uint scoreSpacingY = 0; 
	uint scoreStartX = 0;
	uint scoreStartY = 0;

	uint lifeStartX = 750;
	uint lifeStartY = 0;
	uint lifeHorizontalSpacing = 40;

	uint scoreDigitCount = 6;
	uint gemScore = 250;
	bool hasInitialAmmo = true;
};