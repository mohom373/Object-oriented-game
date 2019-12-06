#include <SFML/Graphics.hpp>
#include <iostream>
#include "Play_State.h"
#include "Constants.h"

int main()
{
	unsigned int window_width = WINDOW_WIDTH;
	unsigned int window_height = WINDOW_HEIGHT;
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), "SFML works!");

	Play_State play(window);

	play.start_game();

	delete window;
	return 0;
}