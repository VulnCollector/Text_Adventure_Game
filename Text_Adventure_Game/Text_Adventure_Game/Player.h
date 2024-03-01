#pragma once
class Player
{
public:
	Player();
	~Player();

	void InBounds(int x, int y);

	int PlayerX;
	int PlayerY;
	int PlayerPrevX;
	int PlayerPrevY;
};

