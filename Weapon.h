#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <string>
///////////////////////////////////////////////////////////
class Human;
using std::string;
///////////////////////////////////////////////////////////
class Weapon
{
public:
	double damage;
	string Name;
	Human *owner;
public:
	Weapon();
	Weapon(double damage_, Human *owner_);
	void setWeapon(double damage_, Human *owner_);
	double weaponDMG();
};

#endif // __WEAPON_H__