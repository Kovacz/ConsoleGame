#ifndef __MAGE_H__
#define __MAGE_H__
#include <string>
#include "Human.h"
///////////////////////////////////////////////////////////
using std::string;
///////////////////////////////////////////////////////////
class Mage : public Human
{
private:
	double mana;
	double damage;
public:
	Mage(string Name, Team *team);
	void information();
	void initWeapon();
	void battleLog();
	void action(Human *unit);
	double getMana();
	double skillCost(double _mana);
	double inflictDMG(double damage);
};

#endif // __MAGE_H__