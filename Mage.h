#ifndef __MAGE_H__
#define __MAGE_H__
#include <string>
///////////////////////////////////////////////////////////
class Human;
using std::string;
///////////////////////////////////////////////////////////
class Mage : public Human
{
private:
	double mana;
public:
	Mage(string Name);
	void information();
	void initWeapon();
	void action(Human *unit);
	double getMana();
	double skillCost(double _mana);
};

#endif // __MAGE_H__