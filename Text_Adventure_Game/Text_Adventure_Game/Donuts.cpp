#include "Donuts.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
using namespace std;
//Random number generator
random_device rnd;
mt19937 genr(rnd());
uniform_int_distribution<int>uni_{ 0,12 };

Donuts::Donuts()
{
	DonutsLeft = uni_(genr); //generate a random number of donuts between 0 and 12.
}

Donuts::~Donuts()
{
}

void Donuts::ItemDescription() const
{
	//print description of donuts along with how many are left
	cout << "a box of donuts. There are " << this->DonutsLeft << " donuts in the box." << endl;
}

void Donuts::UseItem()
{
	//check if there are donuts left. If there are any -1 to DonutsLeft otherwise print there are none.
	if (this->DonutsLeft > 0)
	{
		cout << "You eat a donut." << endl;
		DonutsLeft--;
	}
	else
	{
		cout << "There are no donuts left for you to eat." << endl;
	}
}
