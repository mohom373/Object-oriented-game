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
#include "Triple_Ball.h"

class Play_State {
public:
	Play_State() = default;
	//Play_State(sf::RenderWindow *w);
	Play_State(sf::RenderWindow &w);
	~Play_State() = default;

	void start_game();
	void update(const std::vector<std::shared_ptr<Entity>> &ent);

	void add_entity(const std::shared_ptr<Entity> &new_entity);

	void check_all_collision(std::vector<std::shared_ptr<Ball>> b);
	void render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent);

	int get_lives();

	void set_lives(int l);

	std::vector<std::shared_ptr<Ball>> get_ball();
	void set_ball(std::shared_ptr<Ball> b);


private:
	sf::RenderWindow &window;
	//sf::RenderWindow *game_window;
	std::vector<std::shared_ptr<Ball>> ball{};
	//std::shared_ptr<Entity> ball{};
	//Player player;
	std::shared_ptr<Player> player{};
	std::vector<std::shared_ptr<Point_Zone>> point_zone_container;

	std::shared_ptr<Dead_Zone> dead_zone{};
	//std::vector<std::shared_ptr<Power_Up>> power_up_container;
	std::vector<std::shared_ptr<Triple_Ball>> triple_ball;
	std::vector<std::shared_ptr<Entity>> entity{};

	int lives{};

};


#endif //BALLGAME_PLAY_STATE_H
