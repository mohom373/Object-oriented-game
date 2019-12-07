//
// Created by hamod on 05/12/2019.
//

#include "Entity.h"
Entity::Entity(int w, int h, sf::Vector2f pos, sf::Color c)
	: sf::Sprite(sf::Texture{}, sf::IntRect(sf::Vector2<int>(0,0), sf::Vector2(w,h))),
		width{w}, height{h}
	{
		this->setPosition(pos);
		this->setColor(c);
	}
Entity::Entity() {}