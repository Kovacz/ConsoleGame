#include <string>
#include <iomanip>
#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
#include "Mage.h"
#include "Priest.h"
#include "HitResult.h"
#include "Game.h"

using std::string;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;

Human::~Human()				   { delete weapon;		 }
bool Human::isAlive()		   { return getHP() > 0; }
const string& Human::getName() { return Name;		 }
double Human::getHP()		   { return health;		 }
void Human::battleLog()		   { /*  */ }
void Human::dropWeapon()	   { /*  */ }

Human::Human(string name, Game *game) : Name(name), health(100.0F)
{
	weapon = new Weapon(game->_randomize(), this);
}

bool Human::hasWeapon()
{
	if (weapon == nullptr) { return false; }
	else				   { return true;  }
}

double Human::inflictDMG(double damage)
{
	health -= damage;
	return damage;
}

HitResult Human::hit(Human *unit)
{
	if (!isAlive() || !unit->isAlive())
	{
		cout << "Oops, you're dead already" << endl;
		return HitResult::Suicide;
	}
	if (!hasWeapon())
	{
		cout << "Oops, you don't have weapon, it would be nice to find her first!" << endl;
		return HitResult::Incorrect;
	}
	double damageDone = unit->inflictDMG(weapon->weaponDMG());
	if (!unit->isAlive())
	{
		cout << unit->getName() << " was killed!" << endl;
		return HitResult::Killed;
	}
	if (damageDone <= 0)
	{
		cout << unit->getName() << " missed!" << endl;
		return HitResult::Missed;
	}
	else
	{
		cout << fixed << setprecision(1);
		cout << unit->getName() << " got " << damageDone << " damage." << endl
			 << "Left " << unit->getHP() << " HP" << endl;
		return HitResult::Wounded;
	}
}

void Human::action(Human *unit)
{
	if (hit(unit) == HitResult::Killed)
	{
		cout << getName() << " wins!" << endl;
	}
}

void Human::information()
{
	cout << fixed << setprecision(1);
	cout << endl << "#" << getName() << endl;
	cout << "Weapon: ";
	cout << (hasWeapon() ? "True - " : " False - ");
	cout << weapon->weaponDMG() << "DMG" << endl;
	cout << getHP() << "HP " << endl;
}