#include <string>
#include <iostream>
#include "Human.h"
#include "Mage.h"
#include "Priest.h"
#include "HitResult.h"
#include "Game.h"

using std::string;
using std::cout;
using std::endl;

Priest::Priest(string Name, Game *game) : Mage(Name, game), heal(30.0F) { /*  */ }

double Priest::getHeal() { return heal; }

HitResult Priest::healing()
{
	health += heal;
	mana -= 100;
	battleLog();
	return HitResult::Heal;
}

void Priest::action(Human *unit)
{
	if (health <= 30 && mana >= 100)
	{
		healing();
	}
	else
	{
		Human::action(unit);
	}
}

void Priest::battleLog()
{
	cout << getName() << " heal himself for"
		 << " - " << getHeal() << "HP" << endl
		 << "Left " << getMana() << " Mana" << endl;
}

void Priest::information()
{
	Mage::information();
}