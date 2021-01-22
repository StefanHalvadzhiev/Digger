#pragma once
class Player {
	private:
		unsigned x, y;
		unsigned lives;
		bool ammo;

	public:
		Player();
		~Player();
		Player(const Player& other) = delete;
		Player& operator = (const Player& other) = delete;

		const unsigned& getX();
		const unsigned& getY();

};