//
// Created by hamod on 19/12/2019.
//

#ifndef BALLGAME_RANDOMIZER_H
#define BALLGAME_RANDOMIZER_H

#include <random>


class Randomizer {
public:
	Randomizer();
	int rnd(int a, int b);
	double rnd(double a, double b);

private:
	std::random_device device_;
	std::default_random_engine engine_;
};


#endif //BALLGAME_RANDOMIZER_H
