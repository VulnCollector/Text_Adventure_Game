#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "Item.h"
#include "Cat.h"
#include "Lamp.h"
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

    void AddDesc();



    unsigned mapHeight;
    unsigned mapWidth;

    // Declare a variable that will hold all the characters for the map
    vector<char> Map;
    vector<int> RoomItem;
    vector<Item*> Items;
    vector<string> RoomDesc;
    vector<string> Desc = { "the room is pretty much empty. ", "a water fountain in the middle of the room. ", "a dining table runs almost the entire length of the room. ", "there are various pictures of people hanging on the walls. ", "the room is filled with plants of various types. ", "the room is full of corpses and bones. "};

};

