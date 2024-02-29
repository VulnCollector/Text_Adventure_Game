#include "Room.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int>uni{ 0,2 };



Room::Room()
{
	mapHeight = 5;
	mapWidth = 5;
	Map = { 5 * 5, '.' };
}

Room::Room(unsigned h, unsigned w) : Map(h * w, '.'), RoomItem(h * w)
{
	mapHeight = h;
	mapWidth = w;
	generate(RoomItem.begin(), RoomItem.end(), [&]() {return uni(gen); });
	
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


