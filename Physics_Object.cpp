//
// Created by hamod on 06/12/2019.
//

#include "Physics_Object.h"
Physics_Object::Physics_Object()
	: x_speed{0}, y_speed{0}
	{}
Physics_Object::Physics_Object(float x_speed, float y_speed)
	: x_speed{x_speed}, y_speed{y_speed}
	{}

float Physics_Object::get_x_speed() {
	return x_speed;
}

float Physics_Object::get_y_speed() {
	return y_speed;
}

void Physics_Object::set_x_speed(float x_sp) {
	this->x_speed = x_sp;
}

void Physics_Object::set_y_speed(float y_sp) {
	this->y_speed = y_sp;

}