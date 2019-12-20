//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_MOVABLE_H
#define BALLGAME_MOVABLE_H


#include <SFML/System.hpp>
#include "Physics_Object.h"

class Movable {
public:
	/**
	 * Constructor for Movable class
	 * @param phys_obj
	 */
	Movable(Physics_Object phys_obj): physics_object{phys_obj} {};

	/**
	 * Creates movement of object
	 * @param position
	 */
	virtual void movement(sf::Vector2f &position ) = 0;

protected:
	Physics_Object physics_object{};
};


#endif //BALLGAME_MOVABLE_H
