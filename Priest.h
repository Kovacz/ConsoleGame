#ifndef __PRIEST_H__
#define __PRIEST_H__
#include <string>
#include "Mage.h"
///////////////////////////////////////////////////////////
using std::string;
///////////////////////////////////////////////////////////
class Priest : public Mage
{
private:
	double heal;
	double manaCost;
	unsigned tmp1, tmp2;
public:
	//Priest(string Name, Game *game);
	Priest(string Name, Team *team);
	double getHeal();
	HitResult healing();
	void action(Human *unit);
	void battleLog();
	void initWeapon();
	void information();
};

#endif // __PRIEST_H__