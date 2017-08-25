#include "Team.h"
#include "Arena.h"
#include "Factory.h"
#include "Game.h"

Team::Team(string tName, unsigned tSize) : champions(), Name(tName)
{
	changeTeamSize(tSize);
	form_team();
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

const void Team::changeTeamSize(unsigned &size)
{
	team_size = size;
}

void Team::whoWin()
{
	if (anyOneAlive())
	{
		cout << endl << "/////////////// Congratulations! The " << Name << " team won! ///////////////";
		for (auto i : getVec())
		{
			if (i->isAlive())
			{
				i->information();
			}
		}
		cout << endl;
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
												else if (lhs->isAlive() || rhs->isAlive())
												{
													return rhs->getHP() < lhs->getHP();
												}
											}
									  ); //min_element
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

void Team::form_team()
{
	cout << "Here it is, a ";
	getName();
	cout << " team: " << endl;

	for (int i = 0; i != team_size; i++)
	{
		champions.push_back(init_team()->create(this));
	}

	for (auto i : champions)
	{
		cout.width(10);
		cout << i->getName() << "#" << std::setw(5) << i->getID() << endl;
	}
}

Factory *Team::init_team()
{
	factory[0] = new MageFactory;
	factory[1] = new PriestFactory;
	factory[2] = new WarriorFactory;

	auto result = Game::Instance()._randomize(0, 2);
	return factory[result];
}