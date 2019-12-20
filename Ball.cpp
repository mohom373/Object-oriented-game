//
// Created by hamod on 05/12/2019.
//

#include <random>
#include <iostream>

#include "Ball.h"
#include "Constants.h"
#include "Randomizer.h"


Ball::Ball(sf::Vector2f pos, sf::Color c)
	: Entity{20, 20, pos, c}, Movable{Physics_Object(10.0f, 10.0f)}
	{
		auto randomizer = Randomizer();
		int random_int = randomizer.rnd(0, 1);
		this->rand_direction_decider = random_int;
	}

void Ball::update() {
	auto position = getPosition();

	this->movement(position);
	this->handle_collision(position);
}

void Ball::movement(sf::Vector2f &position) {

	// Traverse left if 0 or right if 1
	if (rand_direction_decider == 0) {
		position.x += physics_object.get_x_speed() ;
		position.y += physics_object.get_y_speed();

	} else if (rand_direction_decider == 1) {
		position.x -= physics_object.get_x_speed() ;
		position.y += physics_object.get_y_speed();
	}

	setPosition(position);
}

void Ball::handle_collision(sf::Vector2f &position) {

	if (position.x <= 0) {
		setPosition(0, position.y);
		physics_object.set_x_speed(- (physics_object.get_x_speed() - extra_speed));

	} else if (position.x + 25 > WINDOW_WIDTH) {
		setPosition(position.x - 25, position.y);
		physics_object.set_x_speed(- (physics_object.get_x_speed() - extra_speed));
	}

	if (position.y <= 10 ) {
		setPosition(position.x, 15);
		physics_object.set_y_speed(- (physics_object.get_y_speed()));
	}
}

void Ball::collision(Play_State &play_state) {
	auto position = getPosition();
	if (physics_object.get_y_speed() > 0 && physics_object.get_x_speed() < 0) {
		setPosition(position.x + width * 0.5f , position.y - height * 1.05f);
		physics_object.set_x_speed(-( physics_object.get_x_speed() - extra_speed ));
		physics_object.set_y_speed(-( physics_object.get_y_speed()  ));

	} else if (physics_object.get_y_speed() > 0 && physics_object.get_x_speed() > 0){
		setPosition(position.x - width * 0.5f, position.y - height * 1.05f);
		physics_object.set_x_speed(-(physics_object.get_x_speed() - extra_speed));
		physics_object.set_y_speed(-( physics_object.get_y_speed() ));

	} else if (physics_object.get_y_speed() < 0 && physics_object.get_x_speed() < 0){
		setPosition(position.x + width * 0.5f, position.y + height * 1.05f);
		physics_object.set_y_speed(-( physics_object.get_y_speed() ));

	} else if (physics_object.get_y_speed() < 0 && physics_object.get_x_speed() > 0){
		setPosition(position.x - width * 0.5f, position.y + height * 1.05f);
		physics_object.set_y_speed(-( physics_object.get_y_speed() ));
	}
}
