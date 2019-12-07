//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_PLAY_STATE_H
#define BALLGAME_PLAY_STATE_H


#include <memory>
#include "Ball.h"
#include "Point_Zone.h"
#include "Player.h"
#include "Dead_Zone.h"
#include "Power_Up.h"

class Play_State {
public:
	Play_State() = default;
	Play_State(sf::RenderWindow *w);
	~Play_State() = default;
	void start_game();
	void update();
	//void render();

private:
	//std::shared_ptr<sf::RenderWindow> window_ptr;

	sf::RenderWindow *game_window;
	//std::vector<Ball> ball_container;
	std::shared_ptr<Entity> ball;
	//Player player;
	std::shared_ptr<Entity> player;
	std::vector<Point_Zone> point_zone_container;

	//Dead_Zone dead_zone;
	std::vector<Power_Up> power_up_container;


	std::vector<std::shared_ptr<Entity>> entity{};
};


#endif //BALLGAME_PLAY_STATE_H
