#include <iostream>
#include "Team.h"
#include "Arena.h"
#include "Mage.h"
#include "Factory.h"

Arena::Arena() : characters(20)
{

}

void Arena::arena_5x5()
{
	Team *blue = new Team;
	Team *red = new Team;

	blue->form_team(characters);
	red->form_team(characters);

	std::cout << "1";

	std::cout << characters.empty();

	for (auto i : characters)
	{
		if (i->getTeam() == blue && i->isAlive() && check == true)
		{
			for (auto j : characters)
			{
				if (j->getTeam() == red && j->isAlive()) 
				{
					i->action(j);
					std::cout << i->getName() << " hit" << j->getName() << std::endl;
				}
			}
			check = false;
		}

		if (i->getTeam() == red && i->isAlive() && check == false)
		{
			for (auto j : characters)
			{
				if (j->getTeam() == blue && j->isAlive())
				{
					i->action(j);
				}
			}
			check = true;
		}
	}
}