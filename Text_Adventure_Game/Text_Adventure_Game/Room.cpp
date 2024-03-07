#include "Room.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include "Item.h"
using namespace std;

//generate random numbers
random_device rd;
mt19937 gen(rd());
mt19937 gen2(rd());
uniform_int_distribution<int>uni{ 0,3 };
uniform_int_distribution<int>uni2{ 0,5 };



Room::Room()
{
	//default initialization of variables and vectors
	mapHeight = 5;
	mapWidth = 5;
	Map = { 5 * 5, '.' };
	RoomItem = { 5 * 5, 0 };
	RoomDesc = { 5 * 5, " "};
	generate(RoomItem.begin(), RoomItem.end(), [&]() {return uni(gen); }); // generate vector of random numbers between 0 and 3
	AddItems();
	AddDesc();
}

Room::Room(unsigned h, unsigned w) : Map(h * w, '.'), RoomItem(h * w), RoomDesc(h * w, " ") //overloaded initialization of variables and vectors
{
	
	mapHeight = h;
	mapWidth = w;
	generate(RoomItem.begin(), RoomItem.end(), [&]() {return uni(gen); }); // generate vector of random numbers between 0 and 3
	AddItems();
	AddDesc();
}

Room::~Room()
{
	
}

unsigned Room::getHeight() const
{
	return mapHeight; //way to access map height
}

unsigned Room::getWidth() const
{
	return mapWidth; //way to access map width
}

char Room::operator()(unsigned y, unsigned x) const
{
	return Map[y * mapWidth + x]; //return a specific point in the map
}

char& Room::operator()(unsigned y, unsigned x)
{
	return Map[y * mapWidth + x]; //return a specific point in the map
}

void Room::PrintMap() const
{
	//print out the map to console
	for (unsigned y = 0; y < getHeight(); ++y) {
		cout << '\t';
		for (unsigned x = 0; x < getWidth(); ++x)
			cout << (*this)(y, x);
		cout << '\n';
	}
	cout << '\n';
}

void Room::AddItems()
{
	//add item to Items vector depending on random number in each element of RoomItem
	for (int i : RoomItem)
	{
		switch (i)
		{
		case 0:
			Items.push_back(new Item());
			break;
		case 1:
			Items.push_back(new Cat());
			break;
		case 2:
			Items.push_back(new Lamp());
			break;
		case 3:
			Items.push_back(new Donuts());
			break;
		default:
			break;
		}
	}
}

void Room::RoomDescription(int i) const
{
	//print out the description of the room depending on player location passed into function
	cout << "You enter the room. Upon entering you notice the " << RoomDesc[i] << endl;
	if (RoomItem[i] == 0)
	{
		cout << "You look around further and don't find any items." << endl;
	}
	else
	{
		cout << "You look around further and find ";
		Items[i]->ItemDescription();
	}
}

void Room::RoomDescShort(int i) const
{
	//shorter version of RoomDescription for when player hasn't entered the room.
	cout << "The " << RoomDesc[i] << endl;
	if (RoomItem[i] == 0)
	{
		cout << "You look around further and don't find any items." << endl;
	}
	else
	{
		cout << "You look around further and find ";
		Items[i]->ItemDescription();
	}
}

void Room::AddDesc()
{
	//get a random description out of the Desc vector and assign it to each element in the RoomDesc Vector
	for (int i = 0; i < RoomDesc.size(); i++)
	{
		RoomDesc[i] = Desc[uni2(gen2)];
	}
}


