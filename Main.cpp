#include "Game.h"

int main()
{
	Pong::Game game(2400, 1350, "Game Of Pong");

	game.run();

	return 0;
}