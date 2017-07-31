#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
Warrior::Warrior(string Name) : Human(Name, 15, 20), armor(0.24F)
{
	//weapon = new Weapon;
	//weapon = new Weapon(Game::Instance()._randomize(urd), this);
}

double Warrior::getArmor() { return armor; }

void Warrior::action(Human *unit)
{
	initWeapon();
	if (!check && keep != 0.0F)
	{
		battleLog();
	}
	check = false;
	Human::action(unit);
}

void Warrior::initWeapon()
{
	if (hasWeapon())
	{
		std::uniform_real_distribution<> urd(15, 20);
		tmp1 = urd.min();
		tmp2 = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Warrior::battleLog()
{
	cout << "Absorbed: " << resist << " of " << keep << "DMG" << endl << endl;
}

double Warrior::inflictDMG(double damage)
{
	keep = damage;
	cout << keep << endl;
	resist = damage * armor;
	damage -= resist;
	Human::inflictDMG(damage);
	return damage;
}

void Warrior::information()
{
	Human::information();
	if (hasWeapon())
	{
		cout << tmp1 << "/" << tmp2 << "DMG";
	}
	cout << endl << getArmor() << " Armor, blocking " << getArmor() * 100 << "% damage" << endl;
}