#include "Human.h"
#include "Weapon.h"
///////////////////////////////////////////////////////////
Weapon::Weapon() { }

Weapon::Weapon(double damage_, Human *owner_) : damage(damage_), owner(owner_) { /*  */ }

void Weapon::setWeapon(double damage_, Human *owner_)
{
	damage = damage_;
	owner = owner_;
}

double Weapon::weaponDMG() { return damage; }