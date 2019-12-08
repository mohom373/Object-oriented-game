//
// Created by hamod on 05/12/2019.
//

#include "Ball.h"
Ball::Ball(sf::Vector2f pos, sf::Color c)
	: Entity{20, 20, pos, c}, Movable{Physics_Object(1.0f, 1.0f)}
	{}

void Ball::update() {
	this->movement();
}

void Ball::movement() {
	sf::Vector2f position = getPosition();

	position.y += physics_object.get_y_speed();
	position.x += physics_object.get_x_speed();
	handle_collision(position);
	setPosition(position);
}

void Ball::handle_collision(sf::Vector2f position) {
	//sf::Vector2f position = getPosition();

	if (position.x < 0 || position.x > 590) {
		physics_object.set_x_speed(-physics_object.get_x_speed());
		//speed_x = -speed_x;
	}

	if (position.y < 0 ) {
		physics_object.set_y_speed(- physics_object.get_y_speed());
	}

}

void Ball::collision(Play_State &play_state) {
	physics_object.set_y_speed(- physics_object.get_y_speed());
}
