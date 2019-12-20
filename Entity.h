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
	/**
	 * Default constructor
	 */
	Entity();

	/**
	 * Constuctor for entity
	 * @param w
	 * @param h
	 * @param pos
	 * @param c
	 */
	Entity(int w, int h, sf::Vector2f pos, sf::Color c);
	Entity(const Entity&) = delete;
	Entity&operator=(const Entity&) = delete;
	~Entity() override = default;

	/**
	 * Updates entity
	 */
	virtual void update() = 0;

	/**
	 * Action after collision has been detected
	 * @param play_state
	 */
	virtual void collision(Play_State &play_state) = 0;

protected:
	int width{};
	int height{};
};


#endif //BALLGAME_ENTITY_H
