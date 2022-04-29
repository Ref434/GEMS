#ifndef Mouse_H
#define Mouse_H
#include <SFML/Graphics.hpp>
using namespace sf;


class MouseTouch
{
public:
	void RightButton(RenderWindow &window, float *x_coordinate, float *y_coordinate);
	void LeftButton(RenderWindow &window, float *x_coordinate, float *y_coordinate);
	bool isRightPressed = false;
	bool isLeftPressed = false;
};


#endif