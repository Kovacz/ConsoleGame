#ifndef __TEAM_H__
#define __TEAM_H__
//#define teamSize 5
///////////////////////////////////////////////////////////
#include <string>
#include <algorithm> 
#include <iostream>
#include <random> 
#include <vector>
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
	unsigned team_size = 0;
	vector<Human *> champions;
	//Human *best_enemy = nullptr;
public:
	Team(string tName, unsigned tSize);
	~Team();
	Factory *init_team();
	void form_team();
	void getName();
	void whoWin();
	const void changeTeamSize(unsigned &size);
	Human *getLeastLivesAlive();
	vector<Human *> getVec();
	bool anyOneAlive();
};

#endif // __TEAM_H__