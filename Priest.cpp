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
Priest::Priest(string Name) : Mage(Name), heal(30.0F)
{ 
	weapon = new Weapon;
}

double Priest::getHeal()   { return heal; }

HitResult Priest::healing()
{
	manaCost = 100;
	health += heal;
	mana -= manaCost;
	battleLog();
	return HitResult::Heal;
}

void Priest::action(Human *unit)
{
	if (health <= 30 && mana >= 100)
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
	std::uniform_real_distribution<> urd(20, 25);
	tmp1 = urd.min();
	tmp2 = urd.max();
	double tmp = Game::Instance()._randomize(urd);
	weapon->setWeapon(tmp, this);
}

void Priest::battleLog()
{
	cout << getName() << " heal himself"
		 << " (+" << getHeal() << "HP|-" << manaCost << "Mana)" << endl
		 << "Left " << getMana() << " Mana" << endl;
}

void Priest::information()
{
	Human::information();
	cout << tmp1 << "/" << tmp2 << "DMG" << endl;
	cout << getMana() << "Mana" << endl;
}