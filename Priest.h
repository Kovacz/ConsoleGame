#ifndef __PRIEST_H__
#define __PRIEST_H__
#include <string>
#include "Mage.h"
///////////////////////////////////////////////////////////
using std::string;
///////////////////////////////////////////////////////////
class Priest : public Mage
{
public:
	double heal;
	double manaCost;
public:
	//Priest(string Name, Game *game);
	Priest(string Name);
	double getHeal();
	HitResult healing();
	void action(Human *unit);
	void battleLog();
	void initWeapon();
	void information();
};

#endif // __PRIEST_H__