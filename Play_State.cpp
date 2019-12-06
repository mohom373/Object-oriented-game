//
// Created by hamod on 05/12/2019.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include "Play_State.h"

#include "Constants.h"
Play_State::Play_State(sf::RenderWindow *w)
	: game_window{w}
	{
		player = std::make_unique<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f), sf::Color::Cyan);
	}

void Play_State::start_game(){

	sf::RenderWindow &window = *(this->game_window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		player->update();
		//ball->update();
		window.draw(*player.get());
		window.display();
	}
}

/*
void Play_State::render() {

}*/
