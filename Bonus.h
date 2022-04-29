#ifndef Bonus_H
#define Bonus_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GEM.h"
using namespace std;
using namespace sf;


class Bonus
{
public:
	Bonus(){ bonus = rand() % 20; };
	void ChangeColor(GEM***D, int i, int j);
	void BOMB(GEM***D);
	int bonus;
};


#endif