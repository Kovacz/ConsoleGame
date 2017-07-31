#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
#include "Mage.h"
#include "Priest.h"
#include "Game.h"
///////////////////////////////////////////////////////////
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
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

unsigned Game::_randomize()
{
	static std::mt19937 genu;
	static std::uniform_int_distribution<> uid(10, 30);

	//srand(time(nullptr));
	//unsigned tmp = rand() % 30 + 10;
	return round(uid(genu));
}

void Game::pvp(Human *unit1, Human *unit2)
{
	while (unit1->isAlive() && unit2->isAlive())
	{
		if (unit1->isAlive())
		{
			unit1->action(unit2);
		}
		if (unit2->isAlive())
		{
			unit2->action(unit1);
		}
	}
}

void Game::Play()
{
	//Mage *mage = new Mage("Mage1", this);
	Warrior *warrior = new Warrior("Warrior1");
	Priest *priest = new Priest("Priest1");

	warrior->dropWeapon();

	pvp(warrior, priest);
	cout << "///////////////Stats of characters///////////////";
	warrior->information();
	priest->information();
}