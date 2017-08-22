#include "Factory.h"

Factory::~Factory() { /*  */ }

//Human *Factory::create(Team *team)
//{ 
//	return new Human("Human", 0, 0, team);
//}

Human *MageFactory::create(Team *team)
{
	return new Mage(team);
}

Human *WarriorFactory::create(Team *team)
{
	return new Warrior(team);
}

Human *PriestFactory::create(Team *team)
{
	return new Priest(team);
}