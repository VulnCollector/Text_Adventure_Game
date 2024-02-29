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

	if (str == "north") return Input::north;
	else if (str == ("east")) return east;
	else if (str == ("west")) return west;
	else if (str == ("south")) return south;
	else if (str == ("quit")) return quit;
	else return nul;
	
}

void Game::Run()
{
	string stop = "";
	
	Input* input = new Input();
	String* command = new String();
	while (stop != "q")
	{
		
		//cout << command->CStr() << endl;
		command->ReadFromConsole();
		command->ToLower();
		
		
		/**input = convert(*command);

		switch (*input)
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
			stop = "q";
			break;
		case nul:
			cout << "Please enter a valid command" << endl;
			break;
		default:
			cout << "Please enter a valid command" << endl;
			break;
		}*/
		
		/*if (command != nullptr)
		{
			delete command;
			command = nullptr;
		}*/
		
	} 
	/*delete command;
	command = nullptr;*/
	delete input;
	input = nullptr;

	exit(0);
	
	
}










