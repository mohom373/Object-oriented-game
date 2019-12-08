#include <SFML/Graphics.hpp>
#include <iostream>
#include "Play_State.h"
#include "Constants.h"

int main()
{
	unsigned int window_width = WINDOW_WIDTH;
	unsigned int window_height = WINDOW_HEIGHT;

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "B & G");
	Play_State game(window);

	game.start_game();

	return 0;
}