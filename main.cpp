#include "Game.h"

/*
implementation
*/
int main()
{
	Game &game = Game::Instance();
	game.Play();

	system("pause");
	return 0;
}