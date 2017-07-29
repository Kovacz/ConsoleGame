#include <random> 
#include <ctime>
#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
#include "Mage.h"
#include "Priest.h"
#include "Game.h"

using std::cout;

Game::Game() : gen(time(nullptr)), urd(15, 35) { /*  */ }
double Game::_randomize() { return urd(gen); }

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
	Mage *mage = new Mage("Mage1", this);
	Warrior *warrior = new Warrior("Warrior1", this);
	Priest *priest = new Priest("Priest1", this);

	pvp(mage, priest);
	cout << "///////////////Stats of characters///////////////";
	mage->information();
	priest->information();
}