#include "Game.h"
Game::Game() : gen(time(nullptr)), urd(15, 35) { /*  */ }
double _randomize() { return urd(gen); }

//template<typename T, typename F>
void pvp(Human *unit1, Human *unit2)
{
	while (unit1->isAlive() && unit2->isAlive()
		/*|| !unit1->isAlive() && !unit2->isAlive()*/)
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

void Play()
{
	Mage *mage = new Mage("Mage1", this);
	Warrior *warrior = new Warrior("Warrior1", this);
	Priest *priest = new Priest("Priest1", this);

	pvp(mage, priest);
	cout << "///////////////Stats of characters///////////////";
	mage->information();
	priest->information();
}