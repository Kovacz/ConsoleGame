#include "Human.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
Weapon::Weapon() { }

Weapon::Weapon(double damage_, Human *owner_) : damage(damage_), owner(owner_) { /*  */ }

const void Weapon::setWeapon(double &damage_, Human *owner_)
{
	damage = damage_;
	owner = owner_;
}

const double Weapon::weaponDMG() 
{ 
		return damage;
}