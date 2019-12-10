//
// Created by hamod on 05/12/2019.
//

//#include <cstdlib>
#include <iostream>
#include "Ball.h"
#include "Constants.h"

Ball::Ball(sf::Vector2f pos, sf::Color c,  int rand_direction_decider)
	: Entity{20, 20, pos, c}, Movable{Physics_Object(1.0f, 1.0f)},
		rand_direction_decider{rand_direction_decider}
	{}

void Ball::update() {
	sf::Vector2f position = getPosition();

	this->movement(position);
	this->handle_collision(position);
	this->setPosition(position);
	//this->setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f));
}

void Ball::movement(sf::Vector2f &position) {

	/*if (rand_direction_decider == 0) {
		position.y += physics_object.get_y_speed();
		position.x += physics_object.get_x_speed();

	} else if (rand_direction_decider == 1) {
		position.y += physics_object.get_y_speed();
		position.x -= physics_object.get_x_speed();
	}*/

	position.y += physics_object.get_y_speed();
	position.x += physics_object.get_x_speed();

}

void Ball::handle_collision(sf::Vector2f &position) {

	if (position.x < 0 || position.x > 580) {
		physics_object.set_x_speed(-physics_object.get_x_speed());
	}

	if (position.y < 0 ) {
		physics_object.set_y_speed(- physics_object.get_y_speed());
	}
}

void Ball::collision(Play_State &play_state) {
	physics_object.set_y_speed(- physics_object.get_y_speed());
}
