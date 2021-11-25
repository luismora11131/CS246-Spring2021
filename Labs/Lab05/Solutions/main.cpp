#include <iostream>
#include <string>
#include "Game.h"

void PlayGame()
{
	Game game;
	int i, j, c;

	while(!game.Success())
	{
		std::cout << game << "\n";
		std::cout << "1. Move Disk\n";
		std::cout << "2. Reset Game\n";
		std::cout << "3. Exit\n\n";
		std::cout << "Enter choice: ";
		std::cin >> c;

		if(c == 1)
		{
			std::cout << "Enter From Tower: ";
			std::cin >> i;
			std::cout << "Enter To Tower: ";
			std::cin >> j;
			std::cout << "move was " << (game.Move(i-1,j-1)?("successful"):("not successful")) << "\n";
		}
		else if(c == 2) 
		{
			game.Reset();
			std::cout << "game is reset\n";
		}
		else if(c == 3) 
		{
			std::cout << "game cancelled\n";
			break;
		}
		else 
		{
			std::cout << "invalid choice\n";
		}
		std::cout << "\n";
	}

	if(game.Success())
	{
		std::cout << "\n" << game << "\n";
	}
}

int main()
{
	PlayGame();
	return 0;
}
