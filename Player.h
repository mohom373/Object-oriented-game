//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_PLAYER_H
#define BALLGAME_PLAYER_H


#include "Entity.h"
#include "Movable.h"

class Player : public Movable, public Entity {
public:
	Player(sf::Vector2f pos, sf::Color c);
	Player(const Player&) = delete;
	Player&operator=(const Player&) = delete;
	~Player() = default;

	void update();
	//void collision();

private:
	void movement();
	//void move();
};


#endif //BALLGAME_PLAYER_H
