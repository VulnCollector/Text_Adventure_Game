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
	else if (str == "use" || str == "u") return use;
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
		player->PlayerPos = player->PlayerY * mapWidth + player->PlayerX;
		
		map->PrintMap();

		map->RoomDescription(player->PlayerPos);

		map->Items[player->PlayerPos]->ItemDescription();

		switch (map->RoomItem[player->PlayerPos])
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
			if (player->PlayerY == 0)
			{
				
			}
			else
			{
				player->PlayerY--;
			}
			
			
			break;
		case south:
			system("CLS");
			cout << "South" << endl;
			if (player->PlayerY == mapHeight - 1) 
			{
				cout << "There is no door" << endl;
			}
			else
			{
				player->PlayerY++;
			}
			
			break;
		case east:
			system("CLS");
			cout << "East" << endl;
			if (player->PlayerX == mapWidth - 1)
			{
				cout << "There is no door" << endl;
			}
			else player->PlayerX++;
			
			break;
		case west:
			system("CLS");
			cout << "West" << endl;
			if (player->PlayerX == 0)
			{
				cout << "There is no door" << endl;
			}
			else player->PlayerX--;
			
			break;
		case quit:
			cout << "quit" << endl;
			stop = "q";
			break;
		case use:
			map->Items[player->PlayerPos]->UseItem();
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










