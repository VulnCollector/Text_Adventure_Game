#include "Cat.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
using namespace std;
//random number generator
random_device r_d;
mt19937 gener(r_d());
uniform_int_distribution<int>unif{ 0,100 };
Cat::Cat()
{
	purring = false;
	

}

Cat::~Cat()
{
}

void Cat::ItemDescription() const
{
	//print Cat description to console. Extra if purring is true
	if (this->purring) cout << "a cat. The cat is purring." << endl;
	else cout << "a cat." << endl;
	
}

void Cat::UseItem()
{
	//use the generator to get 2 random numbers between 0 and 100 everytime the function is called.
	int rand = unif(gener);
	int rand2 = unif(gener);

	//different outcomes of UseItem depending on if purring is true or false.
	if (!this->purring) //if purring is false
	{
		if (rand == 100) //1% chance for this outcome
		{
			cout << "The cat scratches you as you go to pet it." << endl;
		}
		else if (rand < 70) //70% chance for this outcome
		{
			cout << "You pet the cat." << endl;
		}
		else if (rand < 100 && rand >= 70) //29% chance for this outcome. turns purring to true
		{
			cout << "You pet the cat. It starts to purr." << endl;
			this->purring = true;
		}
	}
	else if (this->purring) //if purring is true
	{
		if (rand2 <= 20) //20% chance for purring to become false
		{
			cout << "You pet the cat. It stops purring." << endl;
			this->purring = false;
		}
		else if (rand2 > 20) //80% chance for purring to stay true
		{
			cout << "You pet the cat. It continues to purr." << endl;
		}
	}
}





