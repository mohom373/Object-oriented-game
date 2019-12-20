//
// Created by hamod on 05/12/2019.
//

#include "Triple_Ball.h"
#include "Play_State.h"
#include "Constants.h"

Triple_Ball::Triple_Ball(sf::Vector2f pos, sf::Color c, Power_Up_Interface &pow_up_i)
	: Power_Up{pos, c, 100, 100, power_up_interface}
	{}

void Triple_Ball::update() {

}

void Triple_Ball::collision(Play_State &play_state) {
	// Calls triple_ball_effect method from playstate
	play_state.triple_ball_effect();

	// Remove power up after activation
	play_state.remove_power_up(TRIPLE_BALL_KEY);
}

