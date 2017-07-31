#include "Game.h"
using namespace std;

/*
implementation
*/
int main()
{
	Game &game = Game::Instance();
	game.Play();


	return 0;
}