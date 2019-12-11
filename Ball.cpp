//
// Created by hamod on 05/12/2019.
//

//#include <cstdlib>
#include <iostream>
#include "Ball.h"
#include "Constants.h"
#include <random>

class Randomizer {
public:
	Randomizer() : device_(), engine_(device_()){};
	int rnd(int a, int b) {
		std::uniform_int_distribution<int> uni_dist(a, b);
		return uni_dist(engine_);
	};
	double rnd(double a, double b) {
		std::uniform_real_distribution<double> uni_dist(a, b);
		return uni_dist(engine_);
	};
private:
	std::random_device device_;
	std::default_random_engine engine_;
};

Ball::Ball(sf::Vector2f pos, sf::Color c)
	: Entity{20, 20, pos, c}, Movable{Physics_Object(4.0f, 4.0f)}
	{
		auto randomizer = Randomizer();
		int random_int = randomizer.rnd(0, 1);
		this->rand_direction_decider = random_int;
	}

void Ball::update() {
	sf::Vector2f position = getPosition();

	this->movement(position);
	this->handle_collision(position);
	this->setPosition(position);
	//this->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));
}

void Ball::movement(sf::Vector2f &position) {

	if (rand_direction_decider == 0) {
		position.y += physics_object.get_y_speed();
		position.x += physics_object.get_x_speed() ;

	} else if (rand_direction_decider == 1) {
		position.y += physics_object.get_y_speed();
		position.x -= physics_object.get_x_speed() ;
	}
/*
	position.y += physics_object.get_y_speed();
	position.x += physics_object.get_x_speed();*/

}

void Ball::handle_collision(sf::Vector2f &position) {

	if (position.x < 0 || position.x + 20 > WINDOW_WIDTH) {
		//setPosition(sf::Vector2f(getPosition().x, 11));
		float next_speed = physics_object.get_x_speed();
		float sign = -1*(next_speed > 0 ? 1 : -1);
		next_speed = 4.0f * sign;
		physics_object.set_x_speed(next_speed);

	}

	if (position.y <= 10 ) {
		//setPosition(sf::Vector2f(getPosition().x, 100));
		position.y = 12;
		float next_speed = physics_object.get_y_speed();
		float sign = -1.0*(next_speed > 0 ? 1 : -1);
		next_speed = 4.0f * sign;
		physics_object.set_y_speed(next_speed);
	}
}

void Ball::collision(Play_State &play_state) {
	physics_object.set_y_speed(-(physics_object.get_y_speed() + 5) );
	float pos_x = getPosition().x;
	if(physics_object.get_x_speed() > 0) {
		pos_x -= 10;
	} else {
		pos_x += 10;
	}
	setPosition(pos_x, getPosition().y);
	physics_object.set_x_speed(- physics_object.get_x_speed());

}
