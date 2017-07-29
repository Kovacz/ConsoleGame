#ifndef __MAGE_H__
#define __MAGE_H__

#include <string>
#include "Human.h"

using std::string;

class Mage : public Human
{
public:
	double mana;
public:
	Mage(string Name, Game *game);
	double getMana();
	void information();
};

#endif // __MAGE_H__