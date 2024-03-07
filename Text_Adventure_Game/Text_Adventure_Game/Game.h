#pragma once
#include "string.h"
#include "Room.h"

	enum Input
	{
		north,
		south,
		east,
		west,
		quit,
		use,
		spell,
		nul
	};


class Game
{
public:
	Game();
	~Game();

	void Run();

	void PrintHUD(Room map);


	Input convert(String str);
};

