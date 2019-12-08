//
// Created by hamod on 05/12/2019.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Play_State.h"
#include "Constants.h"

Play_State::Play_State(sf::RenderWindow &w)
		: window{w}
{
	player = std::make_unique<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f), sf::Color::Cyan);
	ball.push_back(std::make_unique<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f), sf::Color::Magenta));
	//ball.push_back(std::make_unique<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 40.0f), sf::Color::Blue));

	dead_zone = std::make_unique<Dead_Zone>(sf::Vector2f(0.0f, WINDOW_HEIGHT - 25.0f), sf::Color::Red);
}

void Play_State::start_game(){
	sf::RenderWindow &window{this->window};

	Play_State::add_entity(player);
	/*for (auto &b : ball) {
		Play_State::add_entity(b);
	}*/
	Play_State::add_entity(ball[0]);
	Play_State::add_entity(dead_zone);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(*player.get());
		//window.draw(*ball.get());
		for (auto &e : entity) {
			e->update();
			window.draw(*e.get());
		}
		//player->update();
		//ball->update();

		//ball->handle_collision();
		this->check_all_collision(ball);
		window.display();
	}
}

void Play_State::add_entity(std::shared_ptr<Entity> new_entity) {
	entity.push_back(new_entity);
}

void Play_State::update() {

}

void Play_State::check_all_collision(std::vector<std::shared_ptr<Ball>> ball) {
	for (auto && ent : entity) {
		for (auto &b : ball) {
			if (ent != b && ent->get_position().intersects(b->get_position())) {
				b->collision(*this);
			}
		}
	}
}



/*
void Play_State::render() {

}*/
