//
// Created by hamod on 05/12/2019.
//

#include "Player.h"
#include "Constants.h"

Player::Player(sf::Vector2f pos, sf::Color c)
	: Entity{200, 20, pos, c}, Movable{Physics_Object(8.0f, 0)}
	{}

void Player::update() {
	sf::Vector2f position = getPosition();

	this->movement(position);
	setPosition(position);

}

void Player::movement(sf::Vector2f &position) {

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		 sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&
		(position.x >= 0 )) {
		 position.x -= physics_object.get_x_speed();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		 sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
		 (position.x <= WINDOW_WIDTH-width)) {
		position.x += physics_object.get_x_speed();
	}
}

void Player::collision(Play_State &play_state) {

}
