#ifndef __MAGE_H__
#define __MAGE_H__
#include <string>
///////////////////////////////////////////////////////////
class Human;
using std::string;
///////////////////////////////////////////////////////////
class Mage : public Human
{
public:
	double mana;
	unsigned tmp1, tmp2;
public:
	Mage(string Name);
	void information();
	void initWeapon();
	void action(Human *unit);
	double getMana();
};

#endif // __MAGE_H__