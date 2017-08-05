#ifndef __TEAM_H__
#define __TEAM_H__
#include "Arena.h"
#include "Factory.h"
///////////////////////////////////////////////////////////
class Human;
///////////////////////////////////////////////////////////
class Team
{
private:
	WarriorFactory *warrior_factory;
	PriestFactory  *priest_factory;
	MageFactory    *mage_factory;

public:
	//Team();
	void add(Human *unit);
	void form_team(vector<Human *> v);

};

#endif // __TEAM_H__