#ifndef __TEAM_H__
#define __TEAM_H__
#define teamSize 5
///////////////////////////////////////////////////////////
#include <string>
#include <algorithm> 
#include <iostream>
#include <random> 
#include <vector> 
#include "Human.h"
///////////////////////////////////////////////////////////
class Human;
class Factory;
using std::string;
using std::cout;
using std::endl;
using std::vector;
///////////////////////////////////////////////////////////
class Team
{
private:
	string Name;
	Factory *factory[3];
	vector<Human *> champions;
	//Human *best_enemy = nullptr;
public:
	Team(string tName);
	~Team();
	Factory *init_team();
	void form_team(vector<Human *> &champions);
	void getName();
	Human *getLeastLivesAlive();
	vector<Human *> getVec();
	bool anyOneAlive();
	bool cmp( Human &lhs,  Human &rhs);
};

#endif // __TEAM_H__