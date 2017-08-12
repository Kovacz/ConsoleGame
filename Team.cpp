#include <iostream>
#include "Team.h"
#include "Factory.h"
//#include "Factory.cpp"

Team::Team(string tName)
{
	Name = tName;
}

void Team::getName()
{
	std::cout << Name;
}


void Team::form_team(vector<Human *> &v)
{
	warrior_factory = new WarriorFactory;
	priest_factory = new PriestFactory;
	mage_factory = new MageFactory;

	std::cout << "Here it is, a ";
	getName();
	std::cout << " team" << std::endl;

	v.push_back(warrior_factory->create("Warrior1", this));
	v.push_back(warrior_factory->create("Warrior2", this));
	v.push_back(priest_factory->create("Priest1", this));
	v.push_back(mage_factory->create("Mage1", this));
	v.push_back(mage_factory->create("Mage2", this));

	for (auto i : v)
	{
		std::cout << i->getName() << std::endl;
	}
}

void Team::add(Human *unit)
{
	//unit->setTeam(this);
}