#pragma once
#include <string>
///////////////////////////////////////////////////////////
class Human;
///////////////////////////////////////////////////////////
class Weapon
{
private:
	double damage = 0.F;
	std::string Name;
	Human *owner  = nullptr;
public:
	Weapon();
	Weapon(double damage_, Human *owner_);
	const void setWeapon(double &damage_, Human *owner_);
	const double weaponDMG();
};