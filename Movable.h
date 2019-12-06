//
// Created by hamod on 05/12/2019.
//

#ifndef BALLGAME_MOVABLE_H
#define BALLGAME_MOVABLE_H


#include "Physics_Object.h"

class Movable {
public:
	Movable(Physics_Object phys_obj): physics_object{phys_obj} {};
	virtual void movement() = 0;

protected:
	Physics_Object physics_object;

};


#endif //BALLGAME_MOVABLE_H
