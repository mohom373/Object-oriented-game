//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_BALL_H
#define BALLGAME_BALL_H


#include "Entity.h"
#include "Movable.h"

class Ball : public Movable, public Entity{
public:
	Ball(sf::Vector2f pos, sf::Color c);
	~Ball() = default;


	void update();
	void handle_collision(sf::Vector2f position);

private:
	void movement();

};


#endif //BALLGAME_BALL_H
