//
// Created by hamod on 05/12/2019.
//

#include <iostream>
#include "Point_Zone.h"
Point_Zone::Point_Zone(sf::Vector2f pos, sf::Color c, int w, int h)
	: Entity{ w, h, pos, c}
	{}

void Point_Zone::update() {

}

void Point_Zone::collision(Play_State &play_state) {
	//points += 50;
	//std::cout << points << std::endl;
}
