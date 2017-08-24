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

bool Team::cmp(Human &lhs, Human &rhs)
{
	if (lhs.isAlive() && rhs.isAlive())
	{
		return lhs.getHP() < rhs.getHP();
	}
}

Human *Team::getLeastLivesAlive()
{
	auto best_enemy = std::min_element(
										champions.begin(), 
										champions.end(), 
										[](Human *lhs, Human *rhs) 
										{ 

											if (lhs->isAlive() && rhs->isAlive())
											{
												return lhs->getHP() < rhs->getHP();
											}

										}
									  ); // min_element
	return (*best_enemy);
}

vector<Human *> Team::getVec()
{
	return champions;
}

bool Team::anyOneAlive()
{
	return std::any_of(champions.begin(), champions.end(), [](Human *h) { return h->isAlive(); });
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