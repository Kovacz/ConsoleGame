#include <string>
#include <iostream>
#include "Human.h"
#include "Mage.h"
#include "Game.h"

using std::string;
using std::cout;
using std::endl;

Mage::Mage(string Name, Game *game) : Human(Name, game), mana(100.0F) { /*  */ }

double Mage::getMana()		{ return mana; }

void   Mage::information()
{
	Human::information();
	cout << getMana() << "Mana" << endl;
}