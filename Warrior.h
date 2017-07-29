#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <string>
class Human;
class Game;

using std::string;

class Warrior : public Human
{
public:
	double armor;
public:
	Warrior(string Name, Game *game);
	double getArmor();
	double inflictDMG(double damage);
	void information();
};

#endif // __WARRIOR_H__