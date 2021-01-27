#pragma once

const struct EngineConstants {
	typedef unsigned int  uint;

	uint screenWidth = 960;
	uint screenHeight = 704;
	uint frameRate = 120;

	uint winPosX = (1920 - screenWidth) / 2;
	uint winPosY = (1080 - screenHeight) / 2;
};