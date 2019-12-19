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

	/*play_state.get_ball().push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
													 sf::Color::Magenta, 0));
	play_state.get_ball().push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
														   sf::Color::Magenta, 1));
*/
	std::cout << "TRipel effetct "<< std::endl;
	play_state.triple_ball_effect();

	play_state.remove_power_up(TRIPLE_BALL_KEY);
	//std::cout << play_state.get_ball().size() << std::endl;

}

