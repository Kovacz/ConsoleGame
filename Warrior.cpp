#include <string>
#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Game.h"

using std::string;
using std::cout;
using std::endl;

Warrior::Warrior(string Name, Game *game) : Human(Name, game), armor(0.2F) { /*  */ }

double Warrior::getArmor() { return armor; }

double Warrior::inflictDMG(double damage)
{
	double resist = damage * armor;
	damage -= resist;
	this->health -= damage;
	return damage;
}

void Warrior::information()
{
	Human::information();
	cout << getArmor() << "Armor" << endl;
}