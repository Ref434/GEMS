#ifndef GAME_H
#define GAME_H




#include <SFML/Graphics.hpp>
#include "GEM.h"
#include "Mouse.h"
#include "Bonus.h"

class Game:GEM
{

public:
	Game(float Width, float Height);
	void run();
	void InitialCheck();
	void DrawGems(sf::RenderWindow &window);
	void CheckAndSwap();
	bool Fix();
	bool AreGemsNearby(int i_gem1,int j_gem1,int i_gem2,int j_gem2);
	~Game();

private:
	float Height;
	float Width;
	int score = 0;
	sf::RenderWindow window;
	GEM ***gems;
	MouseTouch mouse;
	Bonus **bonus;
	/*Bonus ***bonus;*/
};





#endif