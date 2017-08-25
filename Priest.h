#ifndef __PRIEST_H__
#define __PRIEST_H__
///////////////////////////////////////////////////////////
#include <iostream>
#include <string>
///////////////////////////////////////////////////////////
using std::string;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
class Priest : public Human
{
private:
	double healthValue	= 0.0F;
	double mana			= 0.0F;
	double manaCost		= 100.0F;
	double damage		= 0.0F;
	double maxVal		= 0.0F;
	double minVal		= 0.0F;
public:
	Priest(Team *team);
	double getHeal();
	HitResult healing(Human *unit);
	void action(Human *unit);
	void battleLog();
	void initWeapon();
	void information();
	double getMana();
	double skillCost(double _mana);
	double inflictDMG(double damage);
};

#endif // __PRIEST_H__