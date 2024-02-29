#pragma once
#include "string.h"

	enum Input
	{
		north,
		south,
		east,
		west,
		quit,
		nul
	};


class Game
{
public:
	Game();
	~Game();

	void Run();


	Input convert(String str);
};

