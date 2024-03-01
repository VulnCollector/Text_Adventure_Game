#include "Player.h"

Player::Player()
{
	PlayerX = 0;
	PlayerY = 0;
	PlayerPrevX = 0;
	PlayerPrevY = 0;
}

Player::~Player()
{
}

void Player::InBounds(int x, int y)
{
	if ((this->PlayerX > x || this->PlayerY > y) || (this->PlayerX < 0 || this->PlayerY < 0))
	{
		if (this->PlayerX > x) this->PlayerX = this->PlayerPrevX;
		else if (this->PlayerX < 0) this->PlayerX = this->PlayerPrevX;
		else if (this->PlayerY < y) this->PlayerY = this->PlayerPrevY;
		else if (this->PlayerY < 0) this->PlayerY = this->PlayerPrevY;
	}
}
