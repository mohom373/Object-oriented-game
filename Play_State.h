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
	//Play_State() = default; // Default constructor
	//Play_State(sf::RenderWindow &w);
	Play_State();
	~Play_State();

	void start_game(); // Start game loop
	void update(const std::vector<std::shared_ptr<Entity>> &ent); // Update game field

	void add_entity(const std::shared_ptr<Entity> &new_entity); // Add entity to game field
	void check_all_collision(std::vector<std::shared_ptr<Ball>> &b); // Check collision between entities
	void render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent); // Draw entities
	void triple_ball_effect() override; // Activate triple ball effect
	void remove_power_up(std::string key); // Remove power up

	int get_lives(); // Getter for lives
	void set_lives(int l); // Setter for lives

	int get_points();
	void set_points(int p);

private:
	std::shared_ptr<Player> player{};
	std::shared_ptr<Dead_Zone> dead_zone{};

	std::vector<std::shared_ptr<Ball>> ball_container{};
	std::vector<std::shared_ptr<Point_Zone>> point_zone_container;
	std::vector<std::shared_ptr<Entity>> entity{};

	std::map<std::string, Power_Up*> power_up_map;

	int points{};
	int lives{};


	void create_ball();
	void remove_balls(std::vector<int> &vector);

	void spawn_power_up(sf::Clock &clock);

	void create_map();
};


#endif //BALLGAME_PLAY_STATE_H
