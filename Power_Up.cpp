//
// Created by hamod on 05/12/2019.
//

#include "Power_Up.h"

Power_Up::Power_Up(sf::Vector2f pos, sf::Color c, int w, int h, Power_Up_Interface &pow_up_i)
	: Entity{w, h, pos, c}, power_up_interface{pow_up_i}
	{}
