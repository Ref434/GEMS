#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	srand((unsigned int)time(NULL));
	Game gems(840.f, 840.f);
	gems.run();
	return 0;
}