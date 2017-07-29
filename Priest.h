#ifndef __PRIEST_H__
#define __PRIEST_H__

#include <string>
#include "Mage.h"
#include "Game.h"

using std::string;

class Priest : public Mage
{
public:
	double heal;
public:
	Priest(string Name, Game *game);
	double getHeal();
	HitResult healing();
	void action(Human *unit);
	void battleLog();
	void information();
};

#endif // __PRIEST_H__