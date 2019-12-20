//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_BALL_H
#define BALLGAME_BALL_H


#include "Entity.h"
#include "Movable.h"

class Play_State;

/**
 * Ball inherits from Movable and Entity.
 */
class Ball : public Movable, public Entity{
public:
	/**
	 * Constructor for Ball, uses a SFML Vector for position and SMLF Color for color
	 *
	 * @param pos
	 * @param c
	 */
	Ball(sf::Vector2f pos, sf::Color c);
	~Ball() override = default;


	void update() override ;
	void collision(Play_State &play_state) override;

private:
	void handle_collision(sf::Vector2f &position);
	void movement(sf::Vector2f &position) override;

	int rand_direction_decider{};
	float extra_speed{- 3.5f};
};


#endif //BALLGAME_BALL_H
