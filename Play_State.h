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
	Play_State();
	~Play_State();

	/**
	 * Starts the game loop
	 */
	void start_game();

	/**
	 * Updates the game field
	 * @param ent
	 */
	void update(const std::vector<std::shared_ptr<Entity>> &ent);

	/**
	 * Adds entity to game field
	 * @param new_entity
	 */
	void add_entity(const std::shared_ptr<Entity> &new_entity);

	/**
	 * Checks collision between entities
	 * @param b
	 */
	void check_all_collision(std::vector<std::shared_ptr<Ball>> &b);

	/**
	 * Draws entities onto the game field
	 * @param w
	 * @param ent
	 */
	void render(sf::RenderWindow &w, const std::vector<std::shared_ptr<Entity>> &ent);

	/**
	 * Activate the effect of a triple ball power-up
	 */
	void triple_ball_effect() override;

	/**
	 * Removes power up based on a key
	 * @param key
	 */
	void remove_power_up(std::string key);

	/**
	 * Getter for lives
	 * @return an integer that equals amount of lives
	 */
	int get_lives();

	/**
	 * Setter for lives
	 * @param l
	 */
	void set_lives(int l);

	/**
	 * Getter for points
	 * @return an integer that equals amount of points
	 */
	int get_points();

	/**
	 * Setter for points
	 * @param p
	 */
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

	/**
	 * Creates an instance of ball
	 */
	void create_ball();

	/*
	 * Creates the game field
	 */
	void create_map();

	/**
	 * Removes balls from game field
	 * @param vector
	 */
	void remove_balls(std::vector<int> &vector);

	/**
	 * Spawns a power up after a set amount of time
	 * @param clock
	 */
	void spawn_power_up(sf::Clock &clock);
};


#endif //BALLGAME_PLAY_STATE_H
