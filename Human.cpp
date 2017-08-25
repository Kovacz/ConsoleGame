#include "Game.h"
#include "Human.h"
#include "Weapon.h"
#include "HitResult.h"
#include "Team.h"

Human::~Human()				   { delete weapon;		 }
bool Human::isAlive()		   { return getHP() > 0; }
const string& Human::getName() { return Name;		 }
double Human::getHP()		   { return health;		 }
void Human::getTeamName()	   { team->getName();	 }
unsigned Human::getID()		   { return id;			 }
Team *Human::getTeam()		   { return team;		 }
void Human::battleLog()		   { /*  */ }

void Human::setID(unsigned id_)
{ 
	id = id_; 
}

void Human::dropWeapon()
{ 
	if (hasWeapon())
	{
		delete weapon;
		weapon = nullptr;
	}
}

Human::Human(string name, double from, double to, Team *team) : Name(name), health(100.0F)
{
	++id;
	std::uniform_real_distribution<> urd(from, to);
	weapon = new Weapon(Game::Instance()._randomize(urd), this);
	this->team = team;
}

bool Human::hasWeapon()
{
	if (weapon == nullptr) { return false; }
	else				   { return true;  }
}

void Human::initWeapon()
{
	std::uniform_real_distribution<> urd(15, 35);
	double tmp = Game::Instance()._randomize(urd);
	weapon->setWeapon(tmp, this);
}

void Human::action(Human *unit)
{
	if (hit(unit) == HitResult::Killed)
	{
		getTeamName();
		cout << " " << getName() << " wins!" << endl;
	}
}

Weapon *Human::getWeapon()
{
	return weapon;
}

double Human::inflictDMG(double damage)
{
	health -= damage;
	return damage;
}

double Human::heal(double _heal, Human *unit)
{
	health += _heal;
	return health;
}

HitResult Human::hit(Human *unit)
{
	if (!isAlive() || !unit->isAlive())
	{
		cout << "Oops, you're dead already" << endl;
		return HitResult::Suicide;
	}
	if (!hasWeapon())
	{
		cout << "Oops, you don't have weapon, it would be nice to find her first!" << endl;
		return HitResult::Incorrect;
	}
	double damageDone = unit->inflictDMG(this->getWeapon()->weaponDMG());
	if (!unit->isAlive())
	{
		cout << fixed << setprecision(1);
		getTeamName();
		cout << " " << getName() << getID() << " hurt " << this->getWeapon()->weaponDMG() << " DMG" << endl;
		unit->battleLog();
		unit->getTeamName();
		cout << " " << unit->getName() << " was killed!" << endl;
		return HitResult::Killed;
	}
	if (damageDone <= 0)
	{
		cout << unit->getName() << " missed!" << endl;
		return HitResult::Missed;
	}
	else
	{
		cout << fixed << setprecision(1);
		getTeamName();
		cout << " " << getName() << getID() << " hurt " << this->getWeapon()->weaponDMG() << " DMG" << endl;
		unit->battleLog();
		return HitResult::Wounded;
	}
}

void Human::information()
{
	cout << fixed << setprecision(1);
	cout << endl << "#" << getName() << getID() << endl;
	cout << getHP() << "HP " << endl;
	cout << "Weapon: ";
	cout << (hasWeapon() ? "True - " : "False");
}