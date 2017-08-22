#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include <string>
#include <random> 
#include <ctime>
#include "Game.h"
///////////////////////////////////////////////////////////
class Human;
//class Game;
using std::string;
///////////////////////////////////////////////////////////
class Warrior : public Human
{
private:
	bool check = true;
	double armor;
	double resist = 0.0F;
	double keep = 0.0F;
	unsigned tmp1, tmp2 = 0.0F;
public:
	Warrior(Team *team);
	void information();
	void battleLog();
	void initWeapon();
	void action(Human *unit);
	double getArmor();
	double inflictDMG(double damage);
};

#endif // __WARRIOR_H__