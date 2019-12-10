//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_DEAD_ZONE_H
#define BALLGAME_DEAD_ZONE_H


#include <SFML/Graphics.hpp>
#include "Stationary.h"
#include "Entity.h"

class Dead_Zone : public Entity{
public:
	Dead_Zone(sf::Vector2f pos, sf::Color c);
	~Dead_Zone() override = default;

	void update() override;
	void collision(Play_State &play_state) override;

private:

};


#endif //BALLGAME_DEAD_ZONE_H
