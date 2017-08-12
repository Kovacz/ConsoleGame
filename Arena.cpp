#include <iostream>
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

	int i = 0;
	int j = 0;
	vector <Human *> dead;
	while (check)
	{
		for (auto z : team_one)
		{
			for (auto x : team_two)
			{
				std::cout << "///////////" << std::endl;
				std::cout << "Round: " << i << std::endl;
				std::cout << std::endl;
				if (z->isAlive() && z->hasWeapon())
				{
					z->action(x);
				}
				if (x->isAlive() && x->hasWeapon())
				{
					x->action(z);
				}
				else if (!x->isAlive())
				{
					++j;
					if (j == 4)
					{
						check = false;
					}
					dead.push_back(x);
					//team_two.erase(team_two.begin() + j);
				}
				else if (!z->isAlive())
				{
					++i;
					if (i == 4)
					{
						check = false;
					}
					dead.push_back(z);
					//team_two.erase(team_two.begin() + j);
				}
				//if (i >= 4)
				//{
				//	i = 0;
				//}
				//++i;
			}
		}
		std::cout << dead.size() << std::endl;
	}


	//while (team_one[i]->isAlive() || team_two[i]->isAlive())
	//{
	//	std::cout << "///////////" << std::endl;
	//	std::cout << "Round: " << j << std::endl;
	//	std::cout << std::endl;
	//	if (team_one[i]->isAlive() && team_one[i]->hasWeapon())
	//	{
	//		team_one[i]->action(team_two[i]);
	//	}
	//	if (team_two[i]->isAlive() && team_two[i]->hasWeapon())
	//	{
	//		team_two[i]->action(team_one[i]);
	//	}
	//	if (!team_two[i]->isAlive())
	//	{
	//		if (dead.size() == 4)
	//		{
	//			break;
	//		}
	//		dead.push_back(team_two[i]);
	//		std::cout << dead.size() << std::endl;
	//		//team_two.erase(team_two.begin() + i);
	//	}
	//	if (i >= 4)
	//	{
	//		i = 0;
	//	}
	//	++i;
	//	++j;
	//}
	std::cout << "///////////////Stats of Blue Team///////////////";
	for (auto i : team_one)
	{
		i->information();
	}
	std::cout << "///////////////Stats of Red Team///////////////";
	for (auto i : team_two)
	{
		i->information();
	}
}