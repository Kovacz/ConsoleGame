#ifndef __HUMAN_H__
#define __HUMAN_H__
#include <string>
#include <random> 
#include <ctime>
#include "Game.h"
///////////////////////////////////////////////////////////
class Game;
class Weapon;
enum class HitResult;
using std::string;
///////////////////////////////////////////////////////////
class Human
{
public:
	double health;
	string Name;
	Weapon *weapon;
public:
	Human(string name, Game *game);
	Human(string name);
	~Human();
	bool isAlive();
	bool hasWeapon();
	void dropWeapon();
	double getHP();
	const string &getName();
	HitResult hit(Human *unit);
	virtual void battleLog();
	virtual void action(Human *unit);
	virtual void information();
	virtual void initWeapon();
	virtual double inflictDMG(double damage);
};

#endif // __HUMAN_H__