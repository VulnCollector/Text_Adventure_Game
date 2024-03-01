#include "Game.h"
#include "String.h"
#include "Room.h"
#include "Player.h"
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
	
	int mapWidth = 5;
	int mapHeight = 5;
	string stop = "";
	Player* player = new Player();
	Input* input = new Input();
	String* command = new String();
	Room* map = new Room(mapHeight, mapWidth);
	map->Map[player->PlayerPrevX * player->PlayerPrevY] = '.';
	map->Map[player->PlayerX * player->PlayerY] = '@';



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
		
		(*map)(player->PlayerPrevY, player->PlayerPrevX) = '.';
		(*map)(player->PlayerY, player->PlayerX) = '@';
		player->PlayerPrevX = player->PlayerX;
		player->PlayerPrevY = player->PlayerY;
		
		map->PrintMap();

		

		switch (map->RoomItem[player->PlayerY * mapWidth + player->PlayerX])
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
			player->PlayerY--;
			player->InBounds(mapWidth, mapHeight);
			break;
		case south:
			system("CLS");
			cout << "South" << endl;
			player->PlayerY++;
			player->InBounds(mapWidth, mapHeight);
			break;
		case east:
			system("CLS");
			cout << "East" << endl;
			player->PlayerX++;
			player->InBounds(mapWidth, mapHeight);
			break;
		case west:
			system("CLS");
			cout << "West" << endl;
			player->PlayerX--;
			player->InBounds(mapWidth, mapHeight);
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
	delete player;
	player = nullptr;
	delete map;
	map = nullptr;

	exit(0);
	
	
}










