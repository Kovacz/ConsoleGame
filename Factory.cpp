#include "Factory.h"

Factory::~Factory() { /*  */ }

Human *MageFactory::create(string name, Team *team)
{
	return new Mage(name, team);
}

Human *WarriorFactory::create(string name, Team *team)
{
	return new Warrior(name, team);
}

Human *PriestFactory::create(string name, Team *team)
{
	return new Priest(name, team);
}