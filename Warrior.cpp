#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
Warrior::Warrior(Team *team) : Human("Warrior", 15, 20, team), armor(0.24F)
{

}

double Warrior::getArmor() { return armor; }

void Warrior::action(Human *unit)
{
	initWeapon();
	Human::action(unit);
}

void Warrior::initWeapon()
{
	if (hasWeapon())
	{
		std::uniform_real_distribution<> urd(35, 40);
		tmp1 = urd.min();
		tmp2 = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Warrior::battleLog()
{
	getTeamName();
	cout << " " << getName() << " got " << keep << " damage." << endl
		 << "Left " << getHP() << " HP" << endl;
	cout << "Absorbed: " << resist << " of " << keep << "DMG" << endl;
}

double Warrior::inflictDMG(double damage)
{
	keep = damage;
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