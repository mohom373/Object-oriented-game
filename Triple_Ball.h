  //
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_TRIPLE_BALL_H
#define BALLGAME_TRIPLE_BALL_H


#include "Power_Up.h"

class Triple_Ball : public Power_Up{
public:
	/**
	 * Triple ball constructor
	 * @param pos
	 * @param c
	 * @param pow_up_i
	 */
	Triple_Ball(sf::Vector2f pos, sf::Color c, Power_Up_Interface &pow_up_i);
	~Triple_Ball() override = default;

	void update() override;
	void collision(Play_State &play_state) override;
};


#endif //BALLGAME_TRIPLE_BALL_H
