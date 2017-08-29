#ifndef __WARRIOR_H__
#define __WARRIOR_H__
///////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random> 
#include <ctime>
///////////////////////////////////////////////////////////
class Human;
class Game;
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
class Warrior : public Human
{
private:
	bool   check	= true;
	double keep		= 0.0F;
	double armor	= 0.0F;
	double resist	= 0.0F;
	double maxVal	= 0.0F;
	double minVal	= 0.0F;
public:
	Warrior(Team *team);
	~Warrior();
	void information();
	void battleLog();
	void initWeapon();
	void action(Human *unit);
	double getArmor();
	double inflictDMG(double damage);
};

#endif // __WARRIOR_H__