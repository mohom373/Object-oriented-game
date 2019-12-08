//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_PLAY_STATE_H
#define BALLGAME_PLAY_STATE_H


#include <memory>
#include "Point_Zone.h"
#include "Player.h"
#include "Dead_Zone.h"
#include "Power_Up.h"
#include "Ball.h"

class Play_State {
public:
	Play_State() = default;
	//Play_State(sf::RenderWindow *w);
	Play_State(sf::RenderWindow &w);
	~Play_State() = default;

	void start_game();
	void update();

	void add_entity(std::shared_ptr<Entity> new_entity);

	void check_all_collision(std::vector<std::shared_ptr<Ball>> b);
	//void render();

private:
	sf::RenderWindow &window;
	//sf::RenderWindow *game_window;
	std::vector<std::shared_ptr<Ball>> ball{};
	//std::shared_ptr<Entity> ball{};
	//Player player;
	std::shared_ptr<Player> player{};
	std::vector<Point_Zone> point_zone_container;

	std::shared_ptr<Dead_Zone> dead_zone{};
	std::vector<Power_Up> power_up_container;


	std::vector<std::shared_ptr<Entity>> entity{};
};


#endif //BALLGAME_PLAY_STATE_H
