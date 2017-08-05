#include "Team.h"
#include "Factory.h"
//#include "Factory.cpp"


void Team::form_team(vector<Human *> v)
{
	warrior_factory = new WarriorFactory;
	priest_factory = new PriestFactory;
	mage_factory = new MageFactory;

	v.push_back(warrior_factory->create("Warrior1", this));
	v.push_back(warrior_factory->create("Warrior2", this));
	v.push_back(priest_factory->create("Priest1", this));
	v.push_back(mage_factory->create("Mage1", this));
	v.push_back(mage_factory->create("Mage2", this));
}

void Team::add(Human *unit)
{
	//unit->setTeam(this);
}