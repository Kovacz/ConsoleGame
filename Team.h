#ifndef __TEAM_H__
#define __TEAM_H__
#include <string>
#include "Arena.h"
#include "Factory.h"
///////////////////////////////////////////////////////////
class Human;
using std::string;
///////////////////////////////////////////////////////////
class Team
{
private:
	WarriorFactory *warrior_factory;
	PriestFactory  *priest_factory;
	MageFactory    *mage_factory;
	string Name;
public:
	Team(string tName);
	void add(Human *unit);
	void form_team(vector<Human *> &v);
	void getName();
};

#endif // __TEAM_H__