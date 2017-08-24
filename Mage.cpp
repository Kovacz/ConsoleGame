#include "Human.h"
#include "Mage.h"
#include "Weapon.h"
#include "Game.h"

Mage::Mage(Team *team) : Human("Mage", 0, 0, team), mana(100.0F)
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
	if (hasWeapon())
	{
		std::uniform_real_distribution<> urd(35, 45);
		minVal = urd.min();
		maxVal = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Mage::information()
{
	Human::information();
	if (hasWeapon())
	{
		cout << minVal << "/" << maxVal << " DMG";
	}
	cout << endl << getMana() << " Mana" << endl;
}