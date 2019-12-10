//
// Created by hamod on 05/12/2019.
//

#include <iostream>
#include "Triple_Ball.h"
#include "Play_State.h"
#include "Constants.h"

Triple_Ball::Triple_Ball(sf::Vector2f pos, sf::Color c)
	: Entity{100, 50, pos, c}
	{}

void Triple_Ball::update() {

}

void Triple_Ball::collision(Play_State &play_state) {

	/*play_state.get_ball().push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
													 sf::Color::Magenta, 0));
	play_state.get_ball().push_back(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
														   sf::Color::Magenta, 1));
*/
	play_state.set_ball(std::make_shared<Ball>(sf::Vector2f(WINDOW_WIDTH / 2.0f - 10.0f, 150.0f),
											   sf::Color::Magenta, 0));
	std::cout << play_state.get_ball().size() << std::endl;
	/*for (auto &b: play_state.get_ball()) {
		play_state.add_entity(b);
	}*/
}

