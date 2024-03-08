#include "Player.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

Player::Player()
{
	//initialize player variables
	PlayerX = 0;
	PlayerY = 0;
	PlayerPrevX = 0;
	PlayerPrevY = 0;
	PlayerPos = 0;
	PlayerMoved = true;
}

Player::~Player()
{
}

string Player::SpellFind(String spell)
{
	//binary sort to find specific spell in player's spell list
	size_t mid, left = 0;
	size_t right = Spells.size();
	string check = spell.CStr(); // convert player input to string for comparison
	size_t pos = check.find(" ");
	check.erase(0, pos + 1); // remove anything before and including the first space in the player input
	sort(this->Spells.begin(), this->Spells.end()); //sort player spells list

	if (check.length() == 0 || spell.Find("list") != -1 || check == "f" || check == "spell") //if player inputs nothing or list after calling SpellFind print out the list of spells
	{
		for (int i = 0; i < this->Spells.size(); i++)
		{
			if (i == this->Spells.size())
			{
				cout << this->Spells[i];
			}
			else cout << this->Spells[i] << ", ";
			
		}
		return "" + '\n';
	}
	else
	{
		//Binary sort
		while (left < right)
		{
			mid = left + (right - left) / 2;
			transform(this->Spells[mid].begin(), this->Spells[mid].end(), this->Spells[mid].begin(), tolower); //make sure everything in the Spells Vector is lowercase for easier comparison
			if (check > this->Spells[mid])
			{
				left = mid + 1;
			}
			else if (check < this->Spells[mid])
			{
				right = mid;
			}
			else if (check == this->Spells[mid])
			{
				Spells[mid][0] = toupper(Spells[mid][0]); //Make the first character uppercase for printing to console
				cout << "Spell: " << Spells[mid] << " was found in players spellbook.";
				return "" + '\n';
				
			}
			
		}
		cout << "No spell was found with that name.";
		return  "" + '\n';

	}



}



