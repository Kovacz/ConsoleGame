#ifndef __WEAPON_H__
#define __WEAPON_H__

class Weapon
{
public:
	double damage;
	string Name;
	Human *owner;
public:
	Weapon(double damage_, Human *owner_);
	double weaponDMG();
};

#endif // __WEAPON_H__