//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_PLAYER_H
#define BALLGAME_PLAYER_H


#include "Entity.h"

class Player : public Entity {
public:
	Player(float w, float h, sf::Vector2f pos, sf::Color c);
	~Player() = default;

	void update();
private:
};


#endif //BALLGAME_PLAYER_H
