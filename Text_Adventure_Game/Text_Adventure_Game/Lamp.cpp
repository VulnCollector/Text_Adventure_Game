#include "Lamp.h"
#include <iostream>
using namespace std;
Lamp::Lamp()
{
	turnedOn = false;
}

Lamp::~Lamp()
{
}

void Lamp::ItemDescription() const
{
	cout << "a lamp. ";
	if (this->turnedOn)
	{
		cout << "The lamp is on and shining a light throughout the room." << endl;
	}
	else
	{
		cout << "The lamp is off." << endl;
	}
}

void Lamp::UseItem()
{
	if (this->turnedOn)
	{
		cout << "You turn the lamp off." << endl;
		this->turnedOn = false;
	}
	else
	{
		cout << "You turn the lamp on.";
		this->turnedOn = true;
	}
}


