#include "Team.h"
#include "Arena.h"
#include "Mage.h"
#include "Factory.h"
#include "HitResult.h"

Arena::Arena() 
{

}



void Arena::arena_5x5()
{

	std::cout << "Welcome to the Arena, heroes!" << std::endl;

	Team *blue = new Team("Blue");
	Team *red = new Team("Red");

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
	while (check)
	{
		std::cout << "//////////////////////" << std::endl;
		std::cout << "Round: " << i << std::endl;
		std::cout << std::endl;
		if (!blue->anyOneAlive() || !red->anyOneAlive())
		{
			check = false;
		}
		if (qu.front()->isAlive())
		{
			auto fighter = qu.front();
			Team *enemy_team = fighter->getTeam() == red ? blue : red;
			auto best_enemy = enemy_team->getLeastLivesAlive();
			qu.push(fighter);
			qu.pop();

			if (i >= 10 && best_enemy && fighter->isAlive() && fighter->hasWeapon() && best_enemy->getTeam() != fighter->getTeam())
			{
				fighter->action(best_enemy);
				std::cout << "BEST ENEMY: " << std::endl;
				best_enemy->getTeamName();
				std::cout << best_enemy->getName() << " " << best_enemy->getHP() << std::endl;
			}
			else if (i < 10 && fighter->isAlive() && fighter->hasWeapon() && qu.front()->getTeam() != fighter->getTeam())
			{
				fighter->action(qu.front());
			}
		}
		else
		{
			dead.push_back(qu.front());
			qu.pop();
		}
		if (i > 50)
			check = false;
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

	//std::cout << "///////////////Stats of Blue Team///////////////";
	//for (auto i : team_one)
	//{
	//	i->information();
	//}
	//std::cout << "///////////////Stats of Red Team///////////////";
	//for (auto i : team_two)
	//{
	//	i->information();
	//}
}