#include "Game.h"
#include "Human.h"
#include "Weapon.h"
#include "HitResult.h"
#include "Team.h"


Human::~Human()							{ delete weapon;		}
const bool Human::isAlive()				{ return getHP() > 0;	}
const std::string& Human::getName()		{ return Name;			}
const double Human::getHP()				{ return health;		}
void Human::getTeamName()				{ team->getName();		}
const unsigned Human::getID()			{ return id;			}
Team *Human::getTeam()					{ return team;			}
void Human::battleLog()					{ /*...*/ }

void Human::setID(const unsigned &id_)
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

Human::Human(std::string name, double from, double to, Team *team) : Name(name), health(100.0F)
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
		std::cout << " " << getName() << " wins!" << std::endl;
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
		std::cout << "Oops, you're dead already" << std::endl;
		return HitResult::Suicide;
	}
	if (!hasWeapon())
	{
		std::cout << "Oops, you don't have weapon, it would be nice to find her first!" << std::endl;
		return HitResult::Incorrect;
	}
	double damageDone = unit->inflictDMG(this->getWeapon()->weaponDMG());
	if (!unit->isAlive())
	{
		std::cout << std::fixed << std::setprecision(1);
		getTeamName();
		std::cout << " " << getName() << getID() << " hurt " << this->getWeapon()->weaponDMG() << " DMG" << std::endl;
		unit->battleLog();
		unit->getTeamName();
		std::cout << " " << unit->getName() << " was killed!" << std::endl;
		return HitResult::Killed;
	}
	if (damageDone <= 0)
	{
		std::cout << unit->getName() << " missed!" << std::endl;
		return HitResult::Missed;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		getTeamName();
		std::cout << " " << getName() << getID() << " hurt " << this->getWeapon()->weaponDMG() << " DMG" << std::endl;
		unit->battleLog();
		return HitResult::Wounded;
	}
}

void Human::information()
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << std::endl << "#" << getName() << getID() << std::endl;
	std::cout << getHP() << "HP " << std::endl;
	std::cout << "Weapon: ";
	std::cout << (hasWeapon() ? "True - " : "False");
}