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
	//print description of Lamp to console with extras depending if turnedOn is true or false
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
	//make turnedOn true or false to turn the lamp on or off
	if (this->turnedOn)
	{
		cout << "You turn the lamp off." << endl;
		this->turnedOn = false;
	}
	else
	{
		cout << "You turn the lamp on." << endl;
		this->turnedOn = true;
	}
}


