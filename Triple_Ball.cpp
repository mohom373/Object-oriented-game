//
// Created by hamod on 05/12/2019.
//

#include <iostream>
#include "Triple_Ball.h"
#include "Play_State.h"
#include "Constants.h"

Triple_Ball::Triple_Ball(sf::Vector2f pos, sf::Color c, Power_Up_Interface &pow_up_i)
	: Power_Up{pos, c, 100, 100, power_up_interface}
	{}

void Triple_Ball::update() {

}

void Triple_Ball::collision(Play_State &play_state) {

	//std::cout << "TRipel effetct "<< std::endl;
	play_state.triple_ball_effect();

	play_state.remove_power_up(TRIPLE_BALL_KEY);

}

