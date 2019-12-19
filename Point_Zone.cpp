//
// Created by hamod on 05/12/2019.
//

#include <iostream>
#include "Point_Zone.h"
#include "Play_State.h"

Point_Zone::Point_Zone(sf::Vector2f pos, sf::Color c, int w, int h)
	: Entity{ w, h, pos, c}
	{}

void Point_Zone::update() {

}

void Point_Zone::collision(Play_State &play_state) {
	play_state.set_points( 50);
	std::cout << play_state.get_points() << std::endl;
}
