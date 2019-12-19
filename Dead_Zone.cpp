//
// Created by hamod on 05/12/2019.
//

#include "Dead_Zone.h"
#include "Play_State.h"

Dead_Zone::Dead_Zone(sf::Vector2f pos, sf::Color c)
	: Entity{600, 50, pos, c}
	{}

void Dead_Zone::update() {

}

void Dead_Zone::collision(Play_State &play_state) {
	//std::cout << "IM BEING HIT!!!" << std::endl;
	play_state.set_lives(play_state.get_lives() - 1);
}
