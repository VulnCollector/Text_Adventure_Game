#include "Room.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include "Item.h"
using namespace std;

random_device rd;
mt19937 gen(rd());
mt19937 gen2(rd());
uniform_int_distribution<int>uni{ 0,2 };
uniform_int_distribution<int>uni2{ 0,5 };



Room::Room()
{
	mapHeight = 5;
	mapWidth = 5;
	Map = { 5 * 5, '.' };
	RoomItem = { 5 * 5, 0 };
	RoomDesc = { 5 * 5, " "};
	generate(RoomItem.begin(), RoomItem.end(), [&]() {return uni(gen); });
	AddItems();
	AddDesc();
}

Room::Room(unsigned h, unsigned w) : Map(h * w, '.'), RoomItem(h * w), RoomDesc(h * w, " ")
{
	mapHeight = h;
	mapWidth = w;
	generate(RoomItem.begin(), RoomItem.end(), [&]() {return uni(gen); });
	AddItems();
	AddDesc();
}

Room::~Room()
{
	
}

unsigned Room::getHeight() const
{
	return mapHeight;
}

unsigned Room::getWidth() const
{
	return mapWidth;
}

char Room::operator()(unsigned y, unsigned x) const
{
	return Map[y * mapWidth + x];
}

char& Room::operator()(unsigned y, unsigned x)
{
	return Map[y * mapWidth + x];
}

void Room::PrintMap() const
{
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
		default:
			break;
		}
	}
}

void Room::RoomDescription(int i) const
{
	cout << "You Enter the room. Upon entering you notice " << RoomDesc[i] << endl;
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
	for (int i = 0; i < RoomDesc.size(); i++)
	{
		RoomDesc[i] = Desc[uni2(gen2)];
	}
}


