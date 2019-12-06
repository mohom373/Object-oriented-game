//
// Created by hamod on 06/12/2019.
//

#ifndef BALLGAME_PHYSICS_OBJECT_H
#define BALLGAME_PHYSICS_OBJECT_H


class Physics_Object {
public:
	Physics_Object();
	Physics_Object(float x_speed, float y_speed);

	float get_x_speed();
	float get_y_speed();

private:
	float x_speed{};
	float y_speed{};
};


#endif //BALLGAME_PHYSICS_OBJECT_H
