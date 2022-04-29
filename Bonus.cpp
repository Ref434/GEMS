#include "Bonus.h"


void Bonus::ChangeColor(GEM***D,int i,int j)
{
	int g = D[i][j]->GetColor();
	D[i - 1][j - 1]->SetColor(g);
	D[i+1][j+1]->SetColor(g);
	D[i][j]->SetColor((g+1)%4);
	cout << "Bonus 1 activated" << endl;
}


void Bonus::BOMB(GEM***D)
{
	for (size_t i = 0; i < 5; i++)
	{
		int t = rand() % 10;
		int l = rand() % 10;
		for (size_t i = t; i > 0; i--)
		{
			D[t][l]->SetColor(D[t - 1][l]->GetColor());
		}
		D[0][l]->SetColor(rand() % 4);
	}
	cout << "Bonus 2 activated" << endl;

}