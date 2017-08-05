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
	vector<Human *> characters;
public:
	Arena();
	void arena_5x5();
	void arena_deathmatch();
};

#endif // __ARENA_H__
