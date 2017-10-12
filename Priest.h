#pragma once
///////////////////////////////////////////////////////////
#include <iostream>
#include <string>
///////////////////////////////////////////////////////////
class Priest : public Human
{
private:
	double healthValue	= 0.0F;
	double mana			= 0.0F;
	double manaCost		= 100.0F;
	double damage		= 0.0F;
	double maxVal		= 0.0F;
	double minVal		= 0.0F;
public:
	Priest(Team *team);
	~Priest();
	const double getHeal();
	const double getMana();
	HitResult healing(Human *unit);
	void action(Human *unit);
	void battleLog();
	void initWeapon();
	void information();
	double skillCost(const double &_mana);
	double inflictDMG(const double &damage);
};