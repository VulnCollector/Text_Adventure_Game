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
	//checks if input is a correct command then returns the appropriate enum command for switch case.
	if (str == "north" || str == "n") return north;
	else if (str == ("east") || str == "e") return east;
	else if (str == ("west") || str == "w") return west;
	else if (str == ("south") || str == "s") return south;
	else if (str == ("quit") || str == "q") return quit;
	else if (str == "use" || str == "u") return use;
	else if (str.Find("f") == 0 || str.Find("spell") == 0) return spell;
	else return nul;
	
}



void Game::Run()
{
	//set map size and initialize classes.
	int mapWidth = 5;
	int mapHeight = 5;
	string stop = "";
	Player* player = new Player();
	Input* input = new Input();
	String* command = new String();
	Room* map = new Room(mapHeight, mapWidth);
	
	
	while (stop != "q")
	{
		//initialize map and player positions.
		(*map)(player->PlayerPrevY, player->PlayerPrevX) = '.';
		(*map)(player->PlayerY, player->PlayerX) = '@';
		player->PlayerPrevX = player->PlayerX;
		player->PlayerPrevY = player->PlayerY;
		player->PlayerPos = player->PlayerY * mapWidth + player->PlayerX;
		
		if (player->PlayerMoved) //Print the entry room description only if a player has moved rooms
		{
			PrintHUD(*map);

			map->RoomDescription(player->PlayerPos);
		}
		
		//get player command and convert it to lowercase
		cout << "Input Command: " << endl;
		command->ReadFromConsole();
		command->ToLower();
		
		
		//convert the player input into enum for switch case
		*input = convert(*command);

		switch (*input)
		{
		case north:
			system("CLS"); //clear console
			
			if (player->PlayerY == 0) //check if player is moving out of bounds
			{
					//reprint map as well as short description as player hasn't moved out of room
					PrintHUD(*map);
					cout <<  "There is no door in that direction." << '\n' << endl;
					map->RoomDescShort(player->PlayerPos);
					player->PlayerMoved = false;

			}
			else
			{
				// move player 1 room north
				player->PlayerY--;
				player->PlayerMoved = true;
			}
			
			
			break;
		case south:
			system("CLS"); //clear console
			
			if (player->PlayerY == mapHeight - 1)  //check if player is moving out of bounds
			{
				//reprint map as well as short description as player hasn't moved out of room
				PrintHUD(*map);
				cout <<  "There is no door in that direction." << '\n' << endl;
				map->RoomDescShort(player->PlayerPos);
				player->PlayerMoved = false;
			}
			else
			{
				player->PlayerY++;
				player->PlayerMoved = true;
			}
			
			break;
		case east:
			system("CLS"); //clear console
			
			if (player->PlayerX == mapWidth - 1) //check if player is moving out of bounds
			{
				//reprint map as well as short description as player hasn't moved out of room
				PrintHUD(*map);
				cout <<  "There is no door in that direction." << '\n' << endl;
				map->RoomDescShort(player->PlayerPos);
				player->PlayerMoved = false;
			}
			else
			{
				player->PlayerX++;
				player->PlayerMoved = true;
			}
			
			break;
		case west:
			system("CLS"); //clear console
			
			if (player->PlayerX == 0) //check if player is moving out of bounds
			{
				//reprint map as well as short description as player hasn't moved out of room
				PrintHUD(*map);
				cout <<  "There is no door in that direction." << '\n' << endl;
				map->RoomDescShort(player->PlayerPos);
				player->PlayerMoved = false;
			}
			else
			{
				player->PlayerX--;
				player->PlayerMoved = true;
			}
			break;
		case quit:
			cout << "quit" << endl;
			stop = "q";
			break;
		case use:
			system("CLS"); //clear console
			//reprint map then item use as well as short description as player hasn't moved out of room
			PrintHUD(*map);
			map->Items[player->PlayerPos]->UseItem();
			cout << '\n';
			map->RoomDescShort(player->PlayerPos);
			

			player->PlayerMoved = false;
			break;
		case spell:
			system("CLS"); //clear console
			//reprint map then SpellFind as well as short description as player hasn't moved out of room
			PrintHUD(*map);
			cout << player->SpellFind(*command) << endl;
			cout << '\n';
			map->RoomDescShort(player->PlayerPos);
			player->PlayerMoved = false;
			break;
		case nul:
			system("CLS"); //clear console
			//reprint map then an error message as well as short description as player hasn't moved out of room
			PrintHUD(*map);
			cout <<  "Please enter a valid command." << '\n' << endl;
			map->RoomDescShort(player->PlayerPos);
			player->PlayerMoved = false;
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

void Game::PrintHUD(Room map)
{
	map.PrintMap();
	cout << "n - north  |  s - south  |  e - east  |  w - west  |  u - use  |  f - spell  |  q - quit  |" << '\n' << endl;
}











