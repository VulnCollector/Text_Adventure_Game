#pragma once
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Room
{
public:
	Room();

    Room(unsigned h, unsigned w);

	~Room();

    unsigned getHeight() const;
    unsigned getWidth() const;

    char operator()(unsigned y, unsigned x) const;
    char& operator()(unsigned y, unsigned x);

    void PrintMap() const;




    unsigned mapHeight;
    unsigned mapWidth;

    // Declare a variable that will hold all the characters for the map
    vector<char> Map;
    vector<int> RoomItem;
};

