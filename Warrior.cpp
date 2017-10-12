#include "Human.h"
#include "Warrior.h"
#include "Weapon.h"
#include "Game.h"

Warrior::Warrior(Team *team) : Human("Warrior", 0, 0, team), armor(0.24F)
{
	static unsigned war_id = 0;
	Human::setID(++war_id);
}

const double Warrior::getArmor() { return armor; }

void Warrior::action(Human *unit)
{
	initWeapon();
	Human::action(unit);
}

void Warrior::initWeapon()
{
	if (hasWeapon())
	{
		std::uniform_real_distribution<> urd(30, 35);
		minVal = urd.min();
		maxVal = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Warrior::battleLog()
{
	getTeamName();
	std::cout << " " << getName() << getID() << " got " << keep << " DMG of " << getHP() + keep << " HP" << std::endl
		 << "Left " << getHP() << " HP" << std::endl;
	std::cout << "Absorbed: " << resist << " of " << keep << " DMG" << std::endl;
}

double Warrior::inflictDMG(double &damage)
{
	resist = damage * armor;
	damage -= resist;
	keep = damage;
	Human::inflictDMG(damage);
	return damage;
}

void Warrior::information()
{
	Human::information();
	if (hasWeapon())
	{
		std::cout << minVal << "/" << maxVal << " DMG";
	}
	std::cout << std::endl << getArmor() << " Armor, blocking " << getArmor() * 100 << "% damage" << std::endl;
}