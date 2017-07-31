#include <iostream>
#include "Human.h"
#include "Mage.h"
#include "Game.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
Mage::Mage(string Name) : Human(Name), mana(100.0F)
{ 
	weapon = new Weapon;
	//weapon = new Weapon(Game::Instance()._randomize(urd), this);
}

double Mage::getMana() { return mana; }

void Mage::action(Human *unit)
{
	initWeapon();
	Human::action(unit);
}

void Mage::initWeapon()
{
	std::uniform_real_distribution<> urd(20, 35);
	double tmp = Game::Instance()._randomize(urd);
	weapon->setWeapon(tmp, this);
}

void Mage::information()
{
	Human::information();
	cout << getMana() << "Mana" << endl;
}