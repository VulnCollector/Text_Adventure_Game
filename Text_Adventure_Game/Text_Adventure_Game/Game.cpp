#include "Game.h"
#include "String.h"
#include "Room.h"
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

	if (str == "north" || str == "n") return north;
	else if (str == ("east") || str == "e") return east;
	else if (str == ("west") || str == "w") return west;
	else if (str == ("south") || str == "s") return south;
	else if (str == ("quit") || str == "q") return quit;
	else return nul;
	
}



void Game::Run()
{
	int playerXprev = 0;
	int playerYprev = 0;
	int playerX = 0;
	int playerY = 0;
	int mapWidth = 5;
	int mapHeight = 5;
	string stop = "";
	
	Input* input = new Input();
	String* command = new String();
	Room* map = new Room(mapHeight, mapWidth);
	map->Map[playerXprev * playerYprev] = '.';
	map->Map[playerX * playerY] = '@';



	for (int i : map->RoomItem) {
		cout << i << " ";
		switch (i)
		{
		case 0:
			cout << "No Item ";
			break;
		case 1:
			cout << "Cat ";
			break;
		case 2:
			cout << "lamp ";
			break;
		default:
			break;
		}
	}

	
	
		

	
	cout << endl;

	
	while (stop != "q")
	{
		
		(*map)(playerYprev, playerXprev) = '.';
		(*map)(playerY, playerX) = '@';
		playerXprev = playerX;
		playerYprev = playerY;
		
		map->PrintMap();

		

		switch (map->RoomItem[playerY * mapWidth + playerX])
		{
		case 0:
			cout << "No Item " << endl;
			break;
		case 1:
			cout << "Cat " << endl;
			break;
		case 2:
			cout << "lamp " << endl;
			break;
		default:
			break;
		}
		
		command->ReadFromConsole();
		command->ToLower();
		
		
		*input = convert(*command);

		switch (*input)
		{
		case north:
			system("CLS");
			cout << "North" << endl;
			playerY--;
			break;
		case south:
			system("CLS");
			cout << "South" << endl;
			playerY++;
			break;
		case east:
			system("CLS");
			cout << "East" << endl;
			playerX++;
			break;
		case west:
			system("CLS");
			cout << "West" << endl;
			playerX--;
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
		}
		
		
		
	} 
	
	delete input;
	input = nullptr;

	exit(0);
	
	
}










