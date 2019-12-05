//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_ENTITY_H
#define BALLGAME_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Entity {
public:
	Entity();
	Entity(float w, float h, sf::Vector2f pos, sf::Color c);

	virtual ~Entity() = 0;

	virtual void update() = 0;

protected:
	float width{};
	float height{};
	sf::Vector2f position{};
	sf::RectangleShape shape{};
	sf::Color color{};
};


#endif //BALLGAME_ENTITY_H
