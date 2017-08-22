#ifndef __PRIEST_H__
#define __PRIEST_H__
#include <string>
#include "Mage.h"
///////////////////////////////////////////////////////////
using std::string;
///////////////////////////////////////////////////////////
class Priest : public Human
{
private:
	double heal;
	double mana;
	double manaCost = 100;
	double damage;
	int tmp1, tmp2;
public:
	Priest(Team *team);
	double getHeal();
	HitResult healing();
	void action(Human *unit);
	void battleLog();
	void initWeapon();
	void information();
	double getMana();
	double skillCost(double _mana);
	double inflictDMG(double damage);
};

#endif // __PRIEST_H__