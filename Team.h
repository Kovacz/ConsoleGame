#ifndef __TEAM_H__
#define __TEAM_H__
#define teamSize 5
///////////////////////////////////////////////////////////
#include <string>
#include <algorithm> 
#include <iostream>
#include <random> 
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
	vector<Human *> champions;
	string Name;
	Human *best_enemy = nullptr;
public:
	Team(string tName);
	Factory *init_team();
	void form_team(vector<Human *> &champions);
	void getName();
	Human *getLeastLivesAlive();
	vector<Human *> getVec();
	bool anyOneAlive();
	bool getTMP();
};

#endif // __TEAM_H__