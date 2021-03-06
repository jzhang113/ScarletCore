// ScarletCore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScarletCore.h"
#include "Game.h"
#include "windows.h"

const int WIDTH(800);
const int HEIGHT(600);
const std::string NAME("Scarlet Core");

int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);

	Game game(window);
	game.init();
	game.run(window);

	return EXIT_SUCCESS;
}

