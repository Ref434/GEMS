#include "GEM.h"

#include <iostream>
using namespace std;
GEM::GEM(int i,int j,float x_coordinate, float y_coordinate, float height)
{
	this->x_coordinate = x_coordinate;
	this->y_coordinate = y_coordinate;
	this->height = height;
	this->i = i;
	this->j = j;
	color = rand() % 4;
}
GEM::GEM()
{
	this->x_coordinate = 0;
	this->y_coordinate = 0;
	this->height = 0;
}
float GEM::GetYcoordinate()
{
	return y_coordinate;
}
float GEM::GetXcoordinate()
{
	return x_coordinate;
}
float GEM::GetHeight()
{
	return height;
}
void GEM::DrawGEM(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(height, height));
	switch (color)
	{
	case 0:
		rectangle.setFillColor(sf::Color::Green);
		break;
	case 1:
		rectangle.setFillColor(sf::Color::White);
		break;
	case 2:
		rectangle.setFillColor(sf::Color::Blue);
		break;
	case 3:
		rectangle.setFillColor(sf::Color::Red);
		break;
	}
	rectangle.setPosition(x_coordinate, y_coordinate);
	window.draw(rectangle);
}
int GEM::GetColor()
{
	return color;
}
void  GEM::SetColor(int color)
{
	this->color = color;
}