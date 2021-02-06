#pragma once
const struct GameConstants {
	typedef unsigned int uint;
	
	uint playerLives = 3;
	uint maxEnemyCount = 2;
	uint spawnDelay = 1000; // 1000 = 1s 
	bool hasInitialAmmo = true;
};