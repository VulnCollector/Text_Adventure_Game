#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "Item.h"
#include "Cat.h"
#include "Lamp.h"
#include "Donuts.h"
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

    void AddItems();

    void RoomDescription(int i) const;

    void RoomDescShort(int i) const;

    void AddDesc();



    unsigned mapHeight;
    unsigned mapWidth;

    // Declare a variable that will hold all the characters for the map
    vector<char> Map;
    vector<int> RoomItem;
    vector<Item*> Items;
    vector<string> RoomDesc;
    vector<string> Desc = { "room is pretty much empty. ", "room has a water fountain in the middle. ", "room has a dining table that is almost the entire length of the room. ", "room has various pictures of people hanging on the walls. ", "room is filled with plants of various types. ", "room is full of corpses and bones. "};

};

