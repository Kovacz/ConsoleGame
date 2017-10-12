#pragma once
///////////////////////////////////////////////////////////
#include <string>
#include <algorithm> 
#include <iostream>
#include <random> 
#include <vector>
///////////////////////////////////////////////////////////
class Human;
class Factory;
///////////////////////////////////////////////////////////
class Team
{
private:
	std::string Name;
	Factory *factory[3];
	unsigned team_size = 0;
	std::vector<Human *> champions;
	//Human *best_enemy = nullptr;
public:
	Team(std::string tName, const unsigned tSize);
	~Team();
	Factory *init_team();
	void form_team();
	void getName();
	void whoWin();
	const void changeTeamSize(const unsigned &size);
	Human *getLeastLivesAlive();
	std::vector<Human *> getVec();
	bool anyOneAlive();
};