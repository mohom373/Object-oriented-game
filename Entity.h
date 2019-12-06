//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_ENTITY_H
#define BALLGAME_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {
public:
	Entity();
	Entity(int w, int h, sf::Vector2f pos, sf::Color c);

	//virtual ~Entity() = 0;
	~Entity() = default;
	virtual void update() = 0;

protected:
	int width{};
	int height{};
	sf::Vector2f position{};
	sf::Color color{};


};


#endif //BALLGAME_ENTITY_H
