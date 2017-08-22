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
Mage::Mage(Team *team) : Human("Mage", 20, 25, team), mana(100.0F)
{ 

}

double Mage::getMana() { return mana; }

void Mage::action(Human *unit)
{
	initWeapon();
	Human::action(unit);
}

void Mage::battleLog()
{
	getTeamName();
	cout << " " << getName() << " got " << damage << " damage." << endl
		<< "Left " << getHP() << " HP" << endl;
}

double Mage::inflictDMG(double damage)
{
	this->damage = damage;
	Human::inflictDMG(damage);
	return damage;
}

double Mage::skillCost(double _mana)
{
	mana -= _mana;
	return mana;
}

void Mage::initWeapon()
{
	std::uniform_real_distribution<> urd(40, 55);
	double tmp = Game::Instance()._randomize(urd);
	getWeapon()->setWeapon(tmp, this);
}

void Mage::information()
{
	Human::information();
	cout << getMana() << "Mana" << endl;
}