//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_BALL_H
#define BALLGAME_BALL_H


//#include "Play_State.h"
#include "Entity.h"
#include "Movable.h"

class Play_State;

class Ball : public Movable, public Entity{
public:
	Ball(sf::Vector2f pos, sf::Color c);
	~Ball() = default;


	void update() override ;
	void collision(Play_State &play_state) override;


private:
	void handle_collision(sf::Vector2f &position);
	void movement(sf::Vector2f &position) override;

	int rand_direction_decider{};

};


#endif //BALLGAME_BALL_H
