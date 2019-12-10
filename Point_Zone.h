//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_POINT_ZONE_H
#define BALLGAME_POINT_ZONE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Point_Zone : public Entity{
public:
	Point_Zone(sf::Vector2f pos, sf::Color c, int w, int h);
	~Point_Zone() = default;

	void update() override;
	void collision(Play_State &play_state) override;
private:
	int points{};
};


#endif //BALLGAME_POINT_ZONE_H
