//
// Created by hamod on 05/12/2019.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>

#include "Play_State.h"
#include "Constants.h"

Play_State::Play_State(sf::RenderWindow &w)
		: window{w}
{
	player = std::make_shared<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f),
			sf::Color::Cyan);

	ball_container.push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
			sf::Color::Magenta));

/*	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(0.0f, 0.0f),
															   sf::Color::Red, 150, 5));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(250.0f, 0.0f),
																 sf::Color::Green, 150, 75));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(WINDOW_WIDTH - 100.0f, 0.0f),
																 sf::Color::Blue, 150, 5));
	*/
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(250.0f, 0.0f),
																 sf::Color::Blue, 30, 20));


	dead_zone = std::make_shared<Dead_Zone>(sf::Vector2f(0.0f, WINDOW_HEIGHT - 25.0f), sf::Color::Red);


	//triple_ball.push_back(std::make_shared<Triple_Ball>(sf::Vector2f(200.0f, 300.0f), sf::Color::Red));

	power_up_map.insert({TRIPLE_BALL_KEY, new Triple_Ball(sf::Vector2f(100, 100),
			sf::Color::Cyan,*this)});

	lives = 3;
}

void Play_State::start_game(){
	sf::RenderWindow &w{this->window};

	w.setVerticalSyncEnabled(true);
	w.setFramerateLimit(60);

	/*sf::Texture texture;
	if(!texture.loadFromFile("ouf.png"))
	{
		std::cout << "ERROR COULD NOT OPEN FILE" << std::endl;
	}
	sf::Sprite background(texture);
*/

	int temp_lives = lives;

	add_entity(player);

/*	for (auto &b : ball_container) {
		add_entity(b);
	}*/

	for (auto &p_z : point_zone_container) {
		add_entity(p_z);
	}

	//Play_State::add_entity(ball_container[0]);
	add_entity(dead_zone);

/*	for (auto &t_p : triple_ball) {
		add_entity(t_p);
	}*/

	while (w.isOpen())
	{
		sf::Event event;
		while (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				w.close();
		}


		// Update program logic here

		this->check_all_collision(ball_container);
		this->update(entity);

		if (lives < 1) {
			w.close();
		}

		/*if (temp_lives > lives) {
			std::cout << "How many times im in this loop??" << std::endl;
			//ball_container[0]->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));
			ball_container[0]->reset_pos();
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

	for (auto &b : ball_container) {
		b->update();
	}
}

void Play_State::check_all_collision(std::vector<std::shared_ptr<Ball>>& ball_container) {

	for (auto & ent : entity) {
		std::vector<int> erase_index;
		for (int i = 0; i < ball_container.size(); ++i) {
			/*if (ent != b && ent != dead_zone && ent->get_position().intersects(b->get_position())) {
				b->collision(*this);
				ent->collision(*this);
			}

			if (dead_zone->get_position().intersects(b->get_position())) {
				dead_zone->collision(*this);
				//b->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));

			}*/
			auto ball = ball_container[i];
			if (ent != dead_zone && ent->get_position().intersects(ball->get_position())) {
				ball->collision(*this);
				ent->collision(*this);
			}

			if (dead_zone->get_position().intersects(ball->get_position())) {
				//std::cout << "BALL SIZE IS " << ball_container.size() << std::endl;

				erase_index.push_back(i);
				dead_zone->collision(*this);
				//b->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));

			}
		}
		this->remove_balls(erase_index);
	}



	for (auto &p  : power_up_map) {
		if(p.second == nullptr) { continue; }
		for (auto &b : ball_container) {
			if (p.second->get_position().intersects(b->get_position())) {
				b->collision(*this);
				p.second->collision(*this);
			}
		}
	}


	if (ball_container.empty()) {
		create_ball();
		//dead_zone->collision(*this);
	} else {
		//std::cout << "NOOO tOMt" << std::endl;
	}
}

int Play_State::get_lives() {
	return lives;
}

void Play_State::set_lives(int l) {
	if(ball_container.size() > 1) {return;}
	this->lives = l;
}


void Play_State::render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent) {
	for (auto &e : ent ) {
		w.draw(*e.get());
	}

	for (auto &b : ball_container) {
		w.draw(*b.get());
	}

	for(auto &p: power_up_map) {
		if(p.second == nullptr) {continue;}
		w.draw(*p.second);
	}
}


void Play_State::triple_ball_effect() {
	create_ball();
}

void Play_State::size_up_effect() {

}

void Play_State::remove_power_up(std::string key) {
	delete power_up_map[key];
	power_up_map[key] = nullptr;
}

void Play_State::create_ball() {
	std::shared_ptr<Ball> ball = std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
														sf::Color::Magenta);
	this->ball_container.push_back(ball);
	//add_entity(ball);
}

void Play_State::remove_balls(std::vector<int> &vector) {
	for (int i : vector) {


		ball_container.erase(ball_container.begin() + i);
		//std::cout << "BALL SIZE AFTER ERASE " << ball_container.size() << std::endl;

	}
}



