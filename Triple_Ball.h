  //
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_TRIPLE_BALL_H
#define BALLGAME_TRIPLE_BALL_H


#include "Power_Up.h"

class Triple_Ball : public  Entity{
public:
	Triple_Ball(sf::Vector2f pos, sf::Color c);
	~Triple_Ball() = default;

	void update() override;
	void collision(Play_State &play_state) override;
};


#endif //BALLGAME_TRIPLE_BALL_H
