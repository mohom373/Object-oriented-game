//
// Created by hamod on 19/12/2019.
//

#include "Randomizer.h"

Randomizer::Randomizer() :
	device_(), engine_(device_())
	{}



int Randomizer::rnd(int a, int b) {
	std::uniform_int_distribution<int> uni_dist(a, b);
	return uni_dist(engine_);
};
double Randomizer::rnd(double a, double b) {
	std::uniform_real_distribution<double> uni_dist(a, b);
	return uni_dist(engine_);
};