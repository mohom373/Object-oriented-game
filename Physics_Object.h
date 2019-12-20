//
// Created by hamod on 06/12/2019.
//

#ifndef BALLGAME_PHYSICS_OBJECT_H
#define BALLGAME_PHYSICS_OBJECT_H


class Physics_Object {
public:
	/**
	 * Default constructor
	 */
	Physics_Object();

	/**
	 * Constuctor for Physics Object class
	 *
	 * @param x_speed
	 * @param y_speed
	 */
	Physics_Object(float x_speed, float y_speed);

	/**
	 * Getter for x_speed
	 * @return a float that equals to x_speed
	 */
	float get_x_speed();

	/**
	 * Getter for y_speed
	 * @return a float that equals to y_speed
	 */
	float get_y_speed();

	/**
	 * Stter for x_speed
	 * @param x_sp
	 */
	void set_x_speed(float x_sp);

	/**
	 * Setter for y_speed
	 * @param y_sp
	 */
	void set_y_speed(float y_sp);

private:
	float x_speed{};
	float y_speed{};
};


#endif //BALLGAME_PHYSICS_OBJECT_H
