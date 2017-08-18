#ifndef __ARENA_H__
#define __ARENA_H__
#define teamSize 5
///////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <algorithm> 
#include <queue>
///////////////////////////////////////////////////////////
class Human;
class Team;
using std::vector;
using std::queue;
///////////////////////////////////////////////////////////
class Arena
{
private:
	bool check = true;
	int i = 0;
	vector<Human *> characters;
	double b_hp = 0;
	double r_hp = 0;
public:
	Arena();
	void arena_5x5();
	void arena_deathmatch();
};

#endif // __ARENA_H__
