#pragma once
#define teamSize 5
#define twoTeamsSize 10
///////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <algorithm> 
#include <queue>
///////////////////////////////////////////////////////////
class Human;
class Team;
enum class ArenaTypes;
///////////////////////////////////////////////////////////
class Arena
{
private:
	int i = 0;
	Team *red  = nullptr;
	Team *blue = nullptr;
	std::vector<Team *> teams;
public:
	Arena();
	~Arena();
	void arena_type(unsigned type);
	void arena_5x5();
	void pvp(Human *unit1, Human *unit2);
	void arena_deathmatch();
};