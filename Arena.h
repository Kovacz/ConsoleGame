#ifndef __ARENA_H__
#define __ARENA_H__
#include <vector>
///////////////////////////////////////////////////////////
class Human;
class Team;
using std::vector;
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
