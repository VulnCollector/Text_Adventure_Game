#pragma once
#include "Item.h"
class Lamp : public Item
{
public:
	Lamp();
	~Lamp();

	void ItemDescription() const;
	void UseItem();

	bool turnedOn;
};

