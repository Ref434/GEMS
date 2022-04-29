#include "Game.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <cmath>
using namespace std;
using namespace sf;
float x_coord_left_button = 0, y_coord_left_button = 0, x_coord_right_button = 0, y_coord_right_button = 0;
int i_gem1, j_gem1, i_gem2, j_gem2;


Game::Game(float Height, float Width) :GEM()
{
	gems = new GEM**[12];
	bonus = new Bonus*[12];
	for (int i = 0; i <= 12; i++)
	{
		gems[i] = new GEM*[12];
		bonus[i] = new Bonus[12];
	}
	float Heightblock = Height / 15;
	float x_coordinate = 0, y_coordinate = 0;
	for (int i = 0; i <= 12; i++)
	{
		x_coordinate = 0;
		for (int j = 0; j <= 12; j++)
		{
			gems[i][j] = new GEM(i, j, x_coordinate, y_coordinate, Heightblock);
			x_coordinate =5+ x_coordinate + Heightblock;
		}
		y_coordinate = 5+y_coordinate + Heightblock;
	}
	this->Height = Height;
	this->Width = Width;
}


void Game::run()
{
	sf::RenderWindow window(sf::VideoMode((int)Width, (int)Height), "Arcanoid");
	// Declare and load a font
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	// Create a text
	Text text("", font, 20);
	text.setCharacterSize(30);
	text.setStyle(Text::Bold | Text::Underlined);
	text.setColor(Color::Red);
	text.setPosition(700, 750);//задаем позицию текста, отступая от центра камеры
	InitialCheck();
	InitialCheck();
	InitialCheck();
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		std::ostringstream playerScoreString;    // объявили переменную
		playerScoreString << score;		//занесли в нее число очков, то есть формируем строку
		text.setString("Score:" + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		DrawGems(window);
		mouse.LeftButton(window, &x_coord_left_button, &y_coord_left_button);
		mouse.RightButton(window, &x_coord_right_button, &y_coord_right_button);
		CheckAndSwap();
		Fix();
	//	cout << x_coord_left_button;
		window.draw(text);//рисую этот текст
		window.display();
	}
}
void Game::CheckAndSwap()
{

	if (mouse.isLeftPressed && mouse.isRightPressed)
	{
		int i = 0, j = 0;
		for (int i=0; i <= 10; i++)
		{
			for (int j=0; j <= 10; j++)
			{
				if (gems[i][j]->GetXcoordinate() + gems[i][j]->GetHeight() >= x_coord_left_button  && gems[i][j]->GetYcoordinate() + gems[i][j]->GetHeight() >= y_coord_left_button)
				{
					i_gem1 = i;
					j_gem1 = j;
					i = 11;
					j = 11;
				}
			}
		}
		for (int i=0; i <= 10; i++)
		{
			for (int j=0; j <= 10; j++)
			{
				if (gems[i][j]->GetXcoordinate() + gems[i][j]->GetHeight() >= x_coord_right_button  && gems[i][j]->GetYcoordinate() + gems[i][j]->GetHeight() >= y_coord_right_button)
				{
					i_gem2 = i;
					j_gem2 = j;
					i = 11;
					j = 11;
				}
			}
		}
		

		if (AreGemsNearby(i_gem1, j_gem1, i_gem2, j_gem2))
		{
			int color;
			color = gems[i_gem2][j_gem2]->GetColor();
			gems[i_gem2][j_gem2]->SetColor(gems[i_gem1][j_gem1]->GetColor());
			gems[i_gem1][j_gem1]->SetColor(color);

			if (!Fix())
			{
				color = gems[i_gem2][j_gem2]->GetColor();
				gems[i_gem2][j_gem2]->SetColor(gems[i_gem1][j_gem1]->GetColor());
				gems[i_gem1][j_gem1]->SetColor(color);
			}
			else
			{
				if (bonus[i_gem1][j_gem1].bonus == 0)
				{
					bonus[i_gem1][j_gem1].ChangeColor(gems, i_gem1, j_gem1);
				}
				if (bonus[i_gem1][j_gem1].bonus == 1)
				{
					bonus[i_gem1][j_gem1].BOMB(gems);
				}
			}
			
		}
		mouse.isLeftPressed = false;
		mouse.isRightPressed = false;
	}

}


bool Game::Fix()
{
	int NumberGemsSameColor = 1;
	bool isFixed = false;
	for (size_t i = 0; i <= 10; i++)
	{
		for (size_t j = 0; j <= 10; j++)
		{
			
			
			if (gems[i][j]->GetColor() == gems[i][j + 1]->GetColor() && gems[i][j]->GetColor() == gems[i][j + 2]->GetColor())
			{
				while (gems[i][j]->GetColor() == gems[i][j + NumberGemsSameColor]->GetColor() && (j + NumberGemsSameColor)<10)
				{
					NumberGemsSameColor++;
				}
				
				for (size_t s = i; s != 0; --s)
				{
					score++;
					for (size_t t = j; t != j + NumberGemsSameColor + 2 ; ++t)
					{
						gems[s][t]->SetColor(gems[s - 1][t]->GetColor());
					}
				}
				isFixed = true;
				gems[0][j]->SetColor(rand() % 4);
				while (NumberGemsSameColor != 0)
				{
					gems[0][j + NumberGemsSameColor]->SetColor(rand() % 4);
					NumberGemsSameColor--;
				}
				NumberGemsSameColor = 1;

			}
			if (gems[i][j]->GetColor() == gems[i + 1][j]->GetColor() && gems[i][j]->GetColor() == gems[i + 2][j]->GetColor())
			{
				score++;
				for (size_t s = i + 2; s != 2; --s)
				{
					gems[s][j]->SetColor(gems[s - 3][j]->GetColor());
				}
				isFixed = true;
				gems[0][j]->SetColor(rand() % 4);
				gems[1][j]->SetColor(rand() % 4);
				gems[2][j]->SetColor(rand() % 4);
			}
			
		}
	}
	return isFixed;
}
bool Game::AreGemsNearby(int i_gem1, int j_gem1, int i_gem2, int j_gem2)
{
	if ((abs(i_gem2 - i_gem1) == 1 && j_gem2 == j_gem1) || (abs(j_gem2 - j_gem1) == 1 && i_gem2 == i_gem1))
		return true;
	else
		return false;
}

void Game::DrawGems(sf::RenderWindow &window)
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			gems[i][j]->DrawGEM(window);
		}
	}
}

void Game::InitialCheck()
{
	for (size_t i = 0; i != 10; ++i)
	{
		for (size_t j = 0; j != 10; ++j)
		{
			if (gems[i][j]->GetColor() == gems[i][j + 1]->GetColor() && gems[i][j]->GetColor() == gems[i][j + 2]->GetColor())
			{
				gems[i][j + 2]->SetColor((gems[i][j + 2]->GetColor() + 1) % 4);
			}
			if (gems[i][j]->GetColor() == gems[i + 1][j]->GetColor() && gems[i][j]->GetColor() == gems[i + 2][j]->GetColor())
			{
				gems[i + 2][j]->SetColor((gems[i + 2][j]->GetColor() + 1) % 4);
			}
		}
	}

}


Game::~Game()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j <= 12; j++)
		{
			delete[] gems[i][j];
		}
	}
	for (int j = 0; j <= 12; j++)
	{
		delete[] bonus[j];
	}
}

