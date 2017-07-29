#ifndef __PRIEST_H__
#define __PRIEST_H__

#include <string>
class Mage;
class Game;

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