#include "Human.h"
#include "Priest.h"
#include "Weapon.h"
#include "Game.h"
#include "HitResult.h"

Priest::Priest(Team *team) : Human("Priest", 0, 0, team), healthValue(30.0F), mana(100)
{ 
	static unsigned priest_id = 0;
	Human::setID(++priest_id);
}

const double Priest::getHeal()   { return healthValue; }
const double Priest::getMana()   { return mana; }

double Priest::skillCost(const double &_mana)
{
	mana -= _mana;
	return mana;
}

HitResult Priest::healing(Human *unit)
{
	Human::heal(healthValue, unit);
	skillCost(manaCost);
	getTeamName();
	std::cout << " " << getName() << " heal himself"
		<< " (+" << getHeal() << "HP|-" << manaCost << "Mana)" << std::endl
		<< "Left " << getMana() << " Mana" << std::endl;
	return HitResult::Heal;
}

double Priest::inflictDMG(const double &damage)
{
	this->damage = damage;
	Human::inflictDMG(damage);
	return damage;
}

void Priest::action(Human *unit)
{
	if (getHP() <= 30 && getMana() >= 99)
	{
		healing(this);
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
		std::uniform_real_distribution<> urd(30, 40);
		minVal = urd.min();
		maxVal = urd.max();
		double tmp = Game::Instance()._randomize(urd);
		getWeapon()->setWeapon(tmp, this);
	}
}

void Priest::battleLog()
{
	getTeamName();
	std::cout << " " << getName() << getID() << " got " << damage << " DMG of " << getHP() + damage << " HP" << std::endl
		 << "Left " << getHP() << " HP" << std::endl;
}

void Priest::information()
{
	Human::information();
	if (hasWeapon())
	{
		std::cout << minVal << "/" << maxVal << " DMG";
	}
	std::cout << std::endl << getMana() << " Mana" << std::endl;
}