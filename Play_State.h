//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_PLAY_STATE_H
#define BALLGAME_PLAY_STATE_H


#include <memory>
#include <map>
#include "Point_Zone.h"
#include "Player.h"
#include "Dead_Zone.h"
#include "Power_Up.h"
#include "Ball.h"
#include "Triple_Ball.h"
#include "Power_Up_Interface.h"

class Play_State : public Power_Up_Interface{
public:
	Play_State() = default;
	//Play_State(sf::RenderWindow *w);
	Play_State(sf::RenderWindow &w);
	~Play_State() = default;

	void start_game();
	void update(const std::vector<std::shared_ptr<Entity>> &ent);

	void add_entity(const std::shared_ptr<Entity> &new_entity);

	void check_all_collision(std::vector<std::shared_ptr<Ball>> &b);
	void render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent);

	int get_lives();

	void set_lives(int l);


	void triple_ball_effect() override;




	void size_up_effect() override;

	void remove_power_up(std::string key);

private:
	sf::RenderWindow &window;
	//sf::RenderWindow *game_window;
	std::vector<std::shared_ptr<Ball>> ball_container{};
	//std::shared_ptr<Entity> ball{};
	//Player player;
	std::shared_ptr<Player> player{};
	std::vector<std::shared_ptr<Point_Zone>> point_zone_container;

	std::shared_ptr<Dead_Zone> dead_zone{};
	std::map<std::string, Power_Up*> power_up_map;
	std::vector<std::shared_ptr<Triple_Ball>> triple_ball;
	std::vector<std::shared_ptr<Entity>> entity{};

	int lives{};

	void create_ball();

	void remove_balls(std::vector<int> &vector);
};


#endif //BALLGAME_PLAY_STATE_H
