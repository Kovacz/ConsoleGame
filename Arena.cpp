#include "Team.h"
#include "Arena.h"
#include "Factory.h"

Arena::Arena() 
{

}

Arena::~Arena()
{
	delete red;
	delete blue;
}

void Arena::arena_5x5()
{
	std::cout << "Welcome to the Arena, heroes!" << std::endl;

	blue = new Team("Blue");
	red = new Team("Red");

	queue <Human *> qu;
	vector <Human *> dead;

	while (i != teamSize)
	{
		if (!blue->getVec().empty() && !red->getVec().empty())
		{
			qu.push(blue->getVec().at(i));
			qu.push(red->getVec().at(i));
		}
		++i;
	}

	i = 0;
	std::cout << std::endl;
	while (blue->anyOneAlive() && red->anyOneAlive())
	{
		std::cout << "//////////////////////" << std::endl;
		std::cout << "Round: " << i << std::endl;
		std::cout << std::endl;
		if (qu.front()->isAlive())
		{
			auto fighter = qu.front();
			Team *enemy_team = fighter->getTeam() == red ? blue : red;
			auto best_enemy = enemy_team->getLeastLivesAlive();
			qu.push(fighter);
			qu.pop();

			if (i < twoTeamsSize && fighter->isAlive() && fighter->hasWeapon() && qu.front()->getTeam() != fighter->getTeam())
			{
				fighter->action(qu.front());
			}
			else if (i >= twoTeamsSize && best_enemy->isAlive() && fighter->isAlive() && fighter->hasWeapon() && best_enemy->getTeam() != fighter->getTeam())
			{
				fighter->action(best_enemy);
				std::cout << "BEST ENEMY: " << std::endl;
				best_enemy->getTeamName();
				std::cout << " " << best_enemy->getName() << " " << best_enemy->getHP() << std::endl;
			}
		}
		if (!qu.front()->isAlive())
		{
			dead.push_back(qu.front());
			qu.pop();
		}
		++i;
	}


	std::cout << "///////////////Dead///////////////";
	for (auto i : dead)
	{
		std::cout << std::endl;
		std::cout << "Team: ";
		i->getTeamName();
		i->information();
	}

	std::cout << "///////////////Stats of Blue Team///////////////";
	for (auto i : blue->getVec())
	{
		i->information();
	}
	std::cout << "///////////////Stats of Red Team///////////////";
	for (auto j : red->getVec())
	{
		j->information();
	}
}