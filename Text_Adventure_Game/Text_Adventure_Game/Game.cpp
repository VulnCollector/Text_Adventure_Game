#include "Game.h"
#include "String.h"
#include <iostream>
#include <string>
using namespace std;
Game::Game()
{

}

Game::~Game()
{
	
}

Input Game::convert(String str)
{

	if (str.EqualTo("north")) return north;
	else if (str.EqualTo("east")) return east;
	else if (str.EqualTo("west")) return west;
	else if (str.EqualTo("south")) return south;
	else if (str.EqualTo("quit")) return quit;

}

void Game::Run()
{
	String* command = new String();
	while (command->EqualTo("q") == 0)
	{
		command->Replace(command->CStr(), "");
		cout << command->CStr() << endl;
		command->ReadFromConsole();
		command->ToLower();
		
		
		Input input = convert(*command);

		switch (input)
		{
		case north:
			cout << "North" << endl;
			break;
		case south:
			cout << "South" << endl;
			break;
		case east:
			cout << "East" << endl;
			break;
		case west:
			cout << "West" << endl;
			break;
		case quit:
			cout << "quit" << endl;
			command->Replace(command->CStr(), "q");
			cout << command->CStr() << endl;

			break;
		default:
			break;
		}

	} 
	exit(0);
	delete command;
	command = nullptr;
	
}










