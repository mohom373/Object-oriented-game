//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_POWER_UP_H
#define BALLGAME_POWER_UP_H


#include "Entity.h"
#include "Power_Up_Interface.h"

class Power_Up : public Entity{

public:
	/**
	 * Constructor for Power Up class
	 * @param pos
	 * @param c
	 * @param w
	 * @param h
	 * @param pow_up_i
	 */
	Power_Up(sf::Vector2f pos, sf::Color c, int w, int h,
			Power_Up_Interface &pow_up_i);


	~Power_Up() override = default;

	void update() override = 0;

	void collision(Play_State &play_state) override = 0;

protected:
	Power_Up_Interface &power_up_interface;
};


#endif //BALLGAME_POWER_UP_H
