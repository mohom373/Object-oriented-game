//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_POWER_UP_H
#define BALLGAME_POWER_UP_H


#include "Entity.h"
#include "Power_Up_Interface.h"

class Power_Up : public Entity{

public:
	Power_Up(sf::Vector2f pos, sf::Color c, int w, int h,
			Power_Up_Interface &pow_up_i);


	~Power_Up() = default;

	virtual void update() = 0;

	virtual void collision(Play_State &play_state) = 0;

protected:
	Power_Up_Interface &power_up_interface;
};


#endif //BALLGAME_POWER_UP_H
