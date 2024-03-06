#pragma once
#include "string.h"

	enum Input
	{
		north,
		south,
		east,
		west,
		quit,
		use,
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

