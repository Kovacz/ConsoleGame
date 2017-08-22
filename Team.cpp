#include "Team.h"

Team::Team(string tName) : champions(), Name(tName)
{
	form_team(champions);
}

void Team::getName()
{
	cout << Name;
}

Human *Team::getLeastLivesAlive()
{
	static int min_hp = 101;
	for (auto i : champions)
	{
		if (i->getHP() < min_hp && i->isAlive())
		{
			min_hp = i->getHP();
			best_enemy = i;
		}
		else
			min_hp = 101;
	}
	return best_enemy;
}

vector<Human *> Team::getVec()
{
	return champions;
}

bool Team::anyOneAlive()
{
	if (!champions.at(0)->isAlive() && !champions.at(1)->isAlive() && !champions.at(2)->isAlive() && !champions.at(3)->isAlive() && !champions.at(4)->isAlive())
	{
		return false;
	}
	return true;
}

void Team::form_team(vector<Human *> &champions)
{
	std::cout << "Here it is, a ";
	getName();
	std::cout << " team: " << std::endl;

	for (int i = 0; i != teamSize; i++)
	{
		champions.push_back(init_team()->create(this));
	}

	//champions.push_back(warrior_factory->create("Warrior1", this));
	//champions.push_back(warrior_factory->create("Warrior2", this));
	//champions.push_back(priest_factory->create("Priest1", this));
	//champions.push_back(mage_factory->create("Mage1", this));
	//champions.push_back(mage_factory->create("Mage2", this));

	for (auto i : champions)
	{
		cout << i->getName() << endl;
	}
}

Factory *Team::init_team()
{
	Factory *factory[5];
	factory[0] = new MageFactory;
	factory[1] = new PriestFactory;
	factory[2] = new WarriorFactory;

	static std::mt19937 genu(time(nullptr));
	static std::uniform_int_distribution<> uid(0, 2);
	auto result = uid(genu);
	return factory[result];
}