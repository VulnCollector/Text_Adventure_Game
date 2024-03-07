#pragma once
#include "Item.h"
class Donuts :  public Item
{
public:
	Donuts();
	~Donuts();

	void ItemDescription() const;
	void UseItem();

	int DonutsLeft;
};

