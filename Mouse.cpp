#include "Mouse.h"


void MouseTouch::RightButton(RenderWindow &window, float *x_coordinate, float *y_coordinate)
{
	if (Mouse::isButtonPressed(sf::Mouse::Right))
	{
		Vector2i pixelPos;
		pixelPos = Mouse::getPosition(window);
		*x_coordinate = (float)pixelPos.x;
		*y_coordinate = (float)pixelPos.y;
		isRightPressed = true;
	}
}
void MouseTouch::LeftButton(RenderWindow &window, float *x_coordinate, float *y_coordinate)
{
	if (Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Vector2i pixelPos;
		pixelPos = Mouse::getPosition(window);
		*x_coordinate = (float)pixelPos.x;
		*y_coordinate = (float)pixelPos.y;
		isLeftPressed = true;
	}
}