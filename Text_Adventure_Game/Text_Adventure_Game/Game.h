#pragma once
#include "string.h"

	enum Input
	{
		north,
		south,
		east,
		west,
		quit
	};


class Game
{
public:
	Game();
	~Game();

	void Run();


	Input convert(String str);
};

