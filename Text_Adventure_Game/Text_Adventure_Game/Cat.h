#pragma once
#include "Item.h"
class Cat : public Item
{
public:
	Cat();
	~Cat();

	void ItemDescription() const;
};

