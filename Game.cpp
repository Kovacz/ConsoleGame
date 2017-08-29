#include "Human.h"
#include "Weapon.h"
#include "Game.h"
#include "Arena.h"

Game &Game::Instance()
{
	static Game instance;
	return instance;
}

Game::Game() : gen(time(nullptr)), urd(0, 0) { /*  */ }

double Game::_randomize(std::uniform_real_distribution<> urd)
{ 
	return urd(gen); 
}

unsigned Game::_randomize(unsigned from, unsigned to)
{
	static std::mt19937 genu(time(nullptr));
	static std::uniform_int_distribution<> uid(from, to);
	//srand(time(nullptr));
	//unsigned tmp = rand() % 30 + 10;
	return uid(genu);
}

void Game::Play()
{

	unsigned const arena5x5 = 5;
	unsigned const pvp		= 1;

	Arena *arena = new Arena();
	arena->arena_type(arena5x5);

}