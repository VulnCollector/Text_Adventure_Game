#pragma once
class Item
{
public:
	Item();
	~Item();

	virtual void ItemDescription() const;
	virtual void UseItem();
};

