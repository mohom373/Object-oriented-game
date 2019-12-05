#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	unsigned int window_width = 600;
	unsigned int window_height = 1000;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML works!");
	sf::CircleShape shape(70.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}