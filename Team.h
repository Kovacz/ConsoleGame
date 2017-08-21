#ifndef __TEAM_H__
#define __TEAM_H__
///////////////////////////////////////////////////////////
#include <string>
#include <algorithm> 
#include <iostream>
#include <vector> 
#include "Arena.h"
#include "Factory.h"
///////////////////////////////////////////////////////////
class Human;
using std::string;
using std::cout;
using std::endl;
using std::vector;
///////////////////////////////////////////////////////////
class Team
{
private:
	WarriorFactory *warrior_factory;
	PriestFactory  *priest_factory;
	MageFactory    *mage_factory;
	vector<Human *> team_one;
	vector<Human *> team_two;
	string Name;
	Human *best_enemy = nullptr;
public:
	Team(string tName);
	void add(Human *unit);
	void form_team(vector<Human *> &v);
	void getName();
	Human *getLeastLivesAlive();
	vector<Human *> getVec();
	bool anyOneAlive();
	bool getTMP();
};

#endif // __TEAM_H__