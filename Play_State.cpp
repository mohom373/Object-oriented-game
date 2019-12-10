//
// Created by hamod on 05/12/2019.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "Play_State.h"
#include "Constants.h"

Play_State::Play_State(sf::RenderWindow &w)
		: window{w}
{
	player = std::make_shared<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f),
			sf::Color::Cyan);

	ball.push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
			sf::Color::Magenta, (rand() % 2)));

	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(0.0f, 0.0f),
															   sf::Color::Red, 50, 25));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(200.0f, 0.0f),
																 sf::Color::Green, 200, 25));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(WINDOW_WIDTH - 50.0f, 0.0f),
																 sf::Color::Blue, 50, 25));
/*
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(0.0f, 0.0f),
																 sf::Color::Blue, WINDOW_WIDTH, 25));
*/

	dead_zone = std::make_shared<Dead_Zone>(sf::Vector2f(0.0f, WINDOW_HEIGHT - 25.0f), sf::Color::Red);

	lives = 3;
}

void Play_State::start_game(){
	sf::RenderWindow &w{this->window};

	/*sf::Texture texture;
	if(!texture.loadFromFile("ouf.png"))
	{
		std::cout << "ERROR COULD NOT OPEN FILE" << std::endl;
	}
	sf::Sprite background(texture);
*/

	int temp_lives = lives;

	add_entity(player);

	for (auto &b : ball) {
		add_entity(b);
	}

	for (auto &p_z : point_zone_container) {
		add_entity(p_z);
	}

	//Play_State::add_entity(ball[0]);
	add_entity(dead_zone);

	while (w.isOpen())
	{
		sf::Event event;
		while (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				w.close();
		}


		// Update program logic here

		this->check_all_collision(ball);
		this->update(entity);

		if (lives < 1) {
			w.close();
		}

		/*if (temp_lives > lives) {
			std::cout << "How many times im in this loop??" << std::endl;
			//ball[0]->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));
			ball[0]->reset_pos();
		}*/
		w.clear();

		// Draw stuff here

		this->render(w, entity);

		w.display();
	}
}

void Play_State::add_entity(const std::shared_ptr<Entity>& new_entity) {
	entity.push_back(new_entity);
}

void Play_State::update(const std::vector<std::shared_ptr<Entity>> &ent) {
	for (auto &e : ent) {
		e->update();
	}
}

void Play_State::check_all_collision(std::vector<std::shared_ptr<Ball>> ball) {
	for (auto && ent : entity) {
		for (auto &b : ball) {
			if (ent != b && ent->get_position().intersects(b->get_position())) {
				ent->collision(*this);
				b->collision(*this);
			}
		}
	}
}

int Play_State::get_lives() {
	return lives;
}

void Play_State::set_lives(int l) {
	this->lives = l;
}


void Play_State::render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent) {
	for (auto &e : ent ) {
		w.draw(*e.get());
	}
}
