//
// Created by hamod on 05/12/2019.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

#include "Play_State.h"
#include "Constants.h"

/*
Play_State::Play_State(*/
/*sf::RenderWindow &w*//*
)
		: //window{w}
{
	player = std::make_shared<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f),
			sf::Color::White);

	ball_container.push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
			sf::Color::Magenta));

	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(0.0f, 0.0f),
															   sf::Color::Cyan, 15, 150));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(250.0f, 0.0f),
																 sf::Color::Green, 100, 15));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(WINDOW_WIDTH - 150.0f, 0.0f),
																 sf::Color::Blue, 150, 15));

	dead_zone = std::make_shared<Dead_Zone>(sf::Vector2f(0.0f, WINDOW_HEIGHT - 25.0f), sf::Color::Red);

	power_up_map.insert({TRIPLE_BALL_KEY, new Triple_Ball(sf::Vector2f(100, 100),
			sf::Color::Yellow,*this)});

	lives = 3;
}
*/

Play_State::Play_State(/*sf::RenderWindow &w*/)
{
	player = std::make_shared<Player>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 100.0f, WINDOW_HEIGHT - 100.0f),
									  sf::Color::White);

	ball_container.push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
													sf::Color::Magenta));

	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(0.0f, 0.0f),
																 sf::Color::Cyan, 150, 15));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(250.0f, 0.0f),
																 sf::Color::Green, 100, 15));
	point_zone_container.push_back(std::make_shared<Point_Zone>( sf::Vector2f(WINDOW_WIDTH - 150.0f, 0.0f),
																 sf::Color::Blue, 150, 15));

	dead_zone = std::make_shared<Dead_Zone>(sf::Vector2f(0.0f, WINDOW_HEIGHT - 25.0f), sf::Color::Red);



	lives = 3;
}

Play_State::~Play_State() {

		delete power_up_map[TRIPLE_BALL_KEY];
		//power_up_map[Triple_Ball] = nullptr;

}



void Play_State::start_game(){
	//sf::RenderWindow &w{this->window};
	sf::RenderWindow w(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "B & G");

	w.setVerticalSyncEnabled(true);
	w.setFramerateLimit(60);

	/*sf::Texture texture;
	if(!texture.loadFromFile("ouf.png"))
	{
		std::cout << "ERROR COULD NOT OPEN FILE" << std::endl;
	}
	sf::Sprite background(texture);
	*/

	add_entity(player);

	for (auto &p_z : point_zone_container) {
		add_entity(p_z);
	}

	add_entity(dead_zone);



	sf::Clock clock{};
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
		this->spawn_power_up(clock);
		if (lives < 1) {
			w.close();
		}

		w.clear();

		// Draw stuff here
		this->render(w, entity);
		w.display();
	}
}

void Play_State::add_entity(const std::shared_ptr<Entity> &new_entity) {
	entity.push_back(new_entity);
}

void Play_State::update(const std::vector<std::shared_ptr<Entity>> &ent) {

	for (auto &b : ball_container) {
		b->update();
	}
	for (auto &e : ent) {
		e->update();
	}
}

void Play_State::check_all_collision(std::vector<std::shared_ptr<Ball>> &ball_container) {

	for (auto & ent : entity) {
		std::vector<int> erase_index;
		for (int i = 0; i < ball_container.size(); ++i) {
			auto ball = ball_container[i];

			if (ent != dead_zone && ent->getGlobalBounds().intersects(ball->getGlobalBounds())) {
				ball->collision(*this);
				ent->collision(*this);
			}

			if (dead_zone->getGlobalBounds().intersects(ball->getGlobalBounds())) {
				erase_index.push_back(i);
				dead_zone->collision(*this);
			}

		}
		this->remove_balls(erase_index);
	}

	for (auto &p  : power_up_map) {
		if(p.second == nullptr) { continue; }
		for (auto &b : ball_container) {
			if (p.second->getGlobalBounds().intersects(b->getGlobalBounds())) {
				b->collision(*this);
				p.second->collision(*this);
				break;
			}
		}
	}

	if (ball_container.empty()) {
		create_ball();
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
	std::shared_ptr<Ball> b2 = std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
														sf::Color::Magenta);
	std::shared_ptr<Ball> b3 = std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 200.0f),
													  sf::Color::Magenta);
	this->ball_container.push_back(b2);
	this->ball_container.push_back(b3);
	std::cout << ball_container.size() << std::endl;
}

void Play_State::remove_power_up(std::string key) {
	delete power_up_map[key];
	power_up_map[key] = nullptr;
}

void Play_State::create_ball() {

	std::shared_ptr<Ball> ball = std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
														sf::Color::Magenta);
	this->ball_container.push_back(ball);
}

void Play_State::remove_balls(std::vector<int> &vector) {
	for (int i : vector) {
		ball_container.erase(ball_container.begin() + i);
	}
}

void Play_State::spawn_power_up(sf::Clock& clock) {
	auto elapsed = clock.getElapsedTime().asSeconds();
	if(elapsed > 8) {
		if (!power_up_map[TRIPLE_BALL_KEY]) {
			power_up_map[TRIPLE_BALL_KEY] = new Triple_Ball(sf::Vector2f(100, 100), sf::Color::Yellow,*this);
		}
		clock.restart();
	}
}





