#ifndef __ARENA_H__
#define __ARENA_H__
#include <vector>
#include <iostream>
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
	vector<Human *> team_one;
	vector<Human *> team_two;
public:
	Arena();
	void arena_5x5();
	void arena_deathmatch();
};

#endif // __ARENA_H__
