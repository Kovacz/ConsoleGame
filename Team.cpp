#include "Team.h"
#include "Arena.h"
#include "Factory.h"

Team::Team(string tName) : champions(), Name(tName)
{
	form_team(champions);
}

Team::~Team()
{
	for (auto i : factory)
	{
		delete i;
	}
}

void Team::getName()
{
	cout << Name;
}

Human *Team::getLeastLivesAlive()
{
	static double min_hp = 999.0F;
	for (auto i : champions)
	{
		if (i->getHP() < min_hp && i->isAlive())
		{
			min_hp = i->getHP();
			best_enemy = i;
		}
		else
		{
			min_hp = 999.0F;
		}
	}
	return best_enemy;
}

vector<Human *> Team::getVec()
{
	return champions;
}

bool Team::anyOneAlive()
{
	if (std::all_of(champions.begin(), champions.end(), [](Human *h) { return !h->isAlive(); })) 
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

	for (auto i : champions)
	{
		cout << i->getName() << endl;
	}
}

Factory *Team::init_team()
{
	factory[0] = new MageFactory;
	factory[1] = new PriestFactory;
	factory[2] = new WarriorFactory;

	static std::mt19937 genu(time(nullptr));
	static std::uniform_int_distribution<> uid(0, 2);
	auto result = uid(genu);
	return factory[result];
}