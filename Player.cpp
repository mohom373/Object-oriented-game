//
// Created by hamod on 05/12/2019.
//

#include "Player.h"
#include "Constants.h"

Player::Player(sf::Vector2f pos, sf::Color c)
	: Entity{200, 20, pos, c}, Movable{Physics_Object(3.0f, 0)}
	{}

void Player::update() {
	this->movement();
}

void Player::movement(){
	sf::Vector2f position = getPosition();
	//float next_x = position.x
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		 sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&
		(position.x >= 0 ))
	{
		 position.x -= physics_object.get_x_speed();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		 sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (position.x <=
														  WINDOW_WIDTH-width))
	{
		//setPosition()
		position.x += physics_object.get_x_speed();
	}

	setPosition(position);

}