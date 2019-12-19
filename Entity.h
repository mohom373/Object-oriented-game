//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_ENTITY_H
#define BALLGAME_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Play_State;

class Entity : public sf::Sprite {
public:
	Entity();	// Default constructor
	Entity(int w, int h, sf::Vector2f pos, sf::Color c);
	Entity(const Entity&) = delete;
	Entity&operator=(const Entity&) = delete;
	~Entity() override = default; // Default destructor

	virtual void update() = 0; // Update entity
	virtual void collision(Play_State &play_state) = 0; // Action after collision has been detected

protected:
	int width{};
	int height{};
};


#endif //BALLGAME_ENTITY_H
