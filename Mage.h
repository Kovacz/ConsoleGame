#pragma once
///////////////////////////////////////////////////////////
#include <string>
#include <iostream>
///////////////////////////////////////////////////////////
class Mage : public Human
{
private:
	double mana		= 0.0F;
	double damage	= 0.0F;
	double maxVal	= 0.0F;
	double minVal	= 0.0F;
public:
	Mage(Team *team);
	~Mage();
	void information();
	void initWeapon();
	void battleLog();
	void action(Human *unit);
	double getMana() const;
	double skillCost(double _mana);
	double inflictDMG(double damage);
};