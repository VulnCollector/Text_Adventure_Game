#include "Item.h"
#include <iostream>
using namespace std;
Item::Item()
{

}

Item::~Item()
{
}

void Item::ItemDescription() const
{
	cout << "No Item" << endl;
}

void Item::UseItem()
{
	cout << "There is no item to use." << endl;
}



