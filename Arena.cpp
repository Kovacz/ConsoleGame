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

void Arena::arena_type(unsigned type)
{
	if (type == 1)
	{
		blue = new Team("Blue", 1);
		red  = new Team("Red",  1);

		std::cout << std::endl << "It's a pvp between " << blue->getVec().at(0)->getName() << blue->getVec().at(0)->getID()
			 << " and " << red->getVec().at(0)->getName() << red->getVec().at(0)->getID() << std::endl << std::endl;
		pvp(blue->getVec().at(0), red->getVec().at(0));
	}
	else if (type == 5)
	{
		arena_5x5();
	}
	//else if (kind_of_battle == size_deathmatch)
	//{
	//	arena_deathmatch();
	//}
	else
	{
		std::cout << "Oops, something went wrong.." << std::endl;
		exit(1);
	}
}

void Arena::pvp(Human *unit1, Human *unit2)
{
	while (unit1->isAlive() && unit2->isAlive())
	{
		if (unit1->isAlive() && unit1->hasWeapon())
		{
			unit1->action(unit2);
			std::cout << std::endl;
		}
		if (unit2->isAlive() && unit2->hasWeapon())
		{
			unit2->action(unit1);
			std::cout << std::endl;
		}
	}

	red->whoWin();
	blue->whoWin();
}

void Arena::arena_5x5()
{
	std::cout << "Welcome to the Arena, heroes!" << std::endl;

	blue = new Team("Blue", teamSize);
	red  = new Team("Red", teamSize );

	std::queue <Human *> qu;
	std::vector<Human *> dead;

	while ( i != teamSize )
	{
		if ( !blue->getVec().empty() && !red->getVec().empty() )
		{
			qu.push( blue->getVec().at(i) );
			qu.push( red->getVec().at(i)  );
		}
		++i;
	}

	i = 0;
	std::cout << std::endl;
	while ( blue->anyOneAlive() && red->anyOneAlive() )
	{
		std::cout << "//////////////////////" << std::endl;
		std::cout << "Round: " << i << std::endl;
		std::cout << std::endl;

		if (
			      qu.front()->isAlive()
			&&  ( blue->anyOneAlive()	|| red->anyOneAlive() )
		   )
		{
			auto fighter = qu.front();
			Team *enemy_team = fighter->getTeam() == red ? blue : red;
			auto best_enemy = enemy_team->getLeastLivesAlive();
			qu.push(fighter);
			qu.pop();

			if (
				    best_enemy
				&&  best_enemy->isAlive() 
				&&  fighter->isAlive() 
				&&  fighter->hasWeapon() 
				&&  best_enemy->getTeam() != fighter->getTeam()
			   ) 
			{
				fighter->action(best_enemy);
				std::cout << "BEST ENEMY: " << std::endl;
				best_enemy->getTeamName();
				std::cout << " " << best_enemy->getName() << best_enemy->getID() << " " << best_enemy->getHP() << std::endl;
			} /* _if_ */	
			if (!best_enemy->isAlive())
			{
				dead.push_back( best_enemy );
			}
		} /* _if_ */

		if ( !qu.front()->isAlive() )
		{
			qu.pop();
		}

		++i;
	}

	red->whoWin();
	blue->whoWin();

	std::cout << "/////////////// Dead: " << dead.size() << " ///////////////";
	for ( auto i : dead )
	{
		std::cout << std::endl;
		std::cout << "Team: ";
		i->getTeamName();
		i->information();
	}

	//std::cout << "///////////////Stats of Blue Team///////////////";
	//for (auto i : blue->getVec())
	//{
	//	i->information();
	//}
	//std::cout << "///////////////Stats of Red Team///////////////";
	//for (auto j : red->getVec())
	//{
	//	j->information();
	//}
}
