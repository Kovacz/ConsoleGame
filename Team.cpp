#include "Team.h"

Team::Team(string tName) : team_one(), team_two()
{
	if (tName == "Blue")
	{
		Name = "Blue";
		form_team(team_one);
	}
	else if (tName == "Red")
	{
		Name = "Red";
		form_team(team_two);
	}
}

void Team::getName()
{
	cout << Name;
}

//Human Team::weakest()
//{
//	
//}

vector<Human *> Team::getVec()
{
	if (Name == "Blue")
	{
		return team_one;
	}
	else if (Name == "Red")
	{
		return team_two;
	}
}

bool Team::anyOneAlive()
{
	if (Name == "Blue")
	{
		if (!team_one.at(0)->isAlive() && !team_one.at(1)->isAlive() && !team_one.at(2)->isAlive() && !team_one.at(3)->isAlive() && !team_one.at(4)->isAlive())
		{
			return false;
		}
		return true;
	}
	else if (Name == "Red")
	{
		if (!team_two.at(0)->isAlive() && !team_two.at(1)->isAlive() && !team_two.at(2)->isAlive() && !team_two.at(3)->isAlive() && !team_two.at(4)->isAlive())
		{
			return false;
		}
		return true;
	}
}

void Team::form_team(vector<Human *> &v)
{
	warrior_factory = new WarriorFactory;
	priest_factory = new PriestFactory;
	mage_factory = new MageFactory;

	std::cout << "Here it is, a ";
	getName();
	std::cout << " team: " << std::endl;

	v.push_back(warrior_factory->create("Warrior1", this));
	v.push_back(warrior_factory->create("Warrior2", this));
	v.push_back(priest_factory->create("Priest1", this));
	v.push_back(mage_factory->create("Mage1", this));
	v.push_back(mage_factory->create("Mage2", this));

	for (auto i : v)
	{
		cout << i->getName() << endl;
	}
}

void Team::add(Human *unit)
{
	//unit->setTeam(this);
}