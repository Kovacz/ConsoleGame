#include <iostream>
#include "Human.h"
#include "Priest.h"
#include "HitResult.h"
#include "Game.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
Priest::Priest(string Name, Team *team) : Mage(Name, team), heal(30.0F)
{ 
	//weapon = new Weapon;
}

double Priest::getHeal()   { return heal; }

HitResult Priest::healing()
{
	Human::heal(heal);
	Mage::skillCost(manaCost);
	getTeamName();
	cout << " " << getName() << " heal himself"
		<< " (+" << getHeal() << "HP|-" << manaCost << "Mana)" << endl
		<< "Left " << getMana() << " Mana" << endl;
	return HitResult::Heal;
}

double Priest::inflictDMG(double damage)
{
	this->damage = damage;
	Human::inflictDMG(damage);
	return damage;
}

void Priest::action(Human *unit)
{
	if (getHP() <= 30 && getMana() >= 100)
	{
		healing();
	}
	else
	{
		initWeapon();	
		Human::action(unit);
	}
}

void Priest::initWeapon()
{
	if (hasWeapon())
	{
		std::uniform_real_distribution<> urd(30, 45);
		tmp1 = urd.min();
		tmp2 = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Priest::battleLog()
{
	getTeamName();
	cout << " " << getName() << " got " << damage << " damage." << endl
		 << "Left " << getHP() << " HP" << endl;
}

void Priest::information()
{
	Human::information();
	if (hasWeapon())
	{
		cout << tmp1 << "/" << tmp2 << "DMG";
	}
	cout << endl << getMana() << "Mana" << endl;
}