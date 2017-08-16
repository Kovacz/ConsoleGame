#include "Team.h"
#include "Arena.h"
#include "Mage.h"
#include "Factory.h"
#include "HitResult.h"

Arena::Arena() : team_one(), team_two()
{

}

void Arena::arena_5x5()
{

	std::cout << "Welcome to the Arena, heroes!" << std::endl;

	Team *blue = new Team("Blue");
	Team *red = new Team("Red");




	blue->form_team(team_one);
	red->form_team(team_two);

	queue <Human *> qu;
	vector <Human *> dead;

	while (i != team_one.size())
	{
		if (!team_one.empty() && !team_two.empty())
		{
			qu.emplace(team_one.at(i));
			qu.emplace(team_two.at(i));
		}
		++i;
	}

	i = 0;
	std::cout << std::endl;
	while (qu.size() != 4)
	{
		std::cout << "///////////" << std::endl;
		std::cout << "Round: " << i << std::endl;
		std::cout << std::endl;
		if (qu.front()->isAlive() && qu.front()->getTeam() == blue)
		{
			auto temp = qu.front();
			qu.emplace(temp);
			qu.pop();
			if (temp->isAlive() && temp->hasWeapon() && qu.front()->getTeam() == red)
			{
				temp->action(qu.front());
			}
		}
		else if (qu.front()->isAlive() && qu.front()->getTeam() == red)
		{
			auto temp = qu.front();
			qu.emplace(temp);
			qu.pop();
			if (temp->isAlive() && temp->hasWeapon() && qu.front()->getTeam() == blue)
			{
				temp->action(qu.front());
			}
		}
		else
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