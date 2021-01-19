#pragma once
class Player {
	private:
		unsigned x, y;
		unsigned lives;
	public:
		unsigned getX();
		unsigned getY();

		Player();
		~Player();
};