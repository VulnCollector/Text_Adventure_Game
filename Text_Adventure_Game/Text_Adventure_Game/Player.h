#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "String.h"
using namespace std;
class Player
{
public:
	Player();
	~Player();

	string SpellFind(String spell);

	int PlayerX;
	int PlayerY;
	int PlayerPrevX;
	int PlayerPrevY;
	int PlayerPos;
	bool PlayerMoved;

	vector<string> Spells = { "Eclipse", "Eruption", "Frostbite","Levitate","Mirage","Petrify","Polymorph","Teleport","Thunderwave","Vortex" };
	
};

