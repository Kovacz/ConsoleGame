#include "Human.h"
#include "Priest.h"
#include "Weapon.h"
#include "Game.h"
#include "HitResult.h"

Priest::Priest(Team *team) : Human("Priest", 0, 0, team), healthValue(30.0F), mana(100)
{ 

}

double Priest::getHeal()   { return healthValue; }
double Priest::getMana()   { return mana; }

double Priest::skillCost(double _mana)
{
	mana -= _mana;
	return mana;
}

HitResult Priest::healing(Human *unit)
{
	Human::heal(healthValue, unit);
	skillCost(manaCost);
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
	cout << " " << getName() << " got " << damage << " damage." << endl
		 << "Left " << getHP() << " HP" << endl;
}

void Priest::information()
{
	Human::information();
	if (hasWeapon())
	{
		cout << minVal << "/" << maxVal << " DMG";
	}
	cout << endl << getMana() << " Mana" << endl;
}