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
public:
	Mage(string Name, Team *team);
	void information();
	void initWeapon();
	void action(Human *unit);
	double getMana();
	double skillCost(double _mana);
};

#endif // __MAGE_H__