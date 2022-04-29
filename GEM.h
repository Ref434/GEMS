#ifndef GEM_H
#define GEM_H
#include <SFML/Graphics.hpp>


class GEM
{
public:
	GEM();
	GEM(int i,int j,float x_coordinate, float y_coordinate, float height);
	void DrawGEM(sf::RenderWindow &window);
	int GetColor();
	void SetColor(int color);
	float GetYcoordinate();
	float GetHeight();
	float GetXcoordinate();
private:
	float x_coordinate, y_coordinate;
	float height;
	int color;
	int i,j;

};


#endif