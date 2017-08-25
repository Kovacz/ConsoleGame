#ifndef __HUMAN_H__
#define __HUMAN_H__
#include <string>
#include <random> 
#include <ctime>
#include <iomanip>
#include <iostream>
///////////////////////////////////////////////////////////
class Game;
class Team;
class Weapon;
enum class HitResult;
using std::string;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
class Human
{
private:
	string Name;
	unsigned id		= 0;
	double health	= 0.0F;
	Team *team		= nullptr;
	Weapon *weapon	= nullptr;
public:
	Human(string name, double from, double to, Team *team);
	~Human();
	bool isAlive();
	double getHP();
	bool hasWeapon();
	unsigned getID();
	void dropWeapon();
	void getTeamName();
	void setID(unsigned id_);
	const string &getName();
	Team *getTeam();
	Weapon *getWeapon();
	HitResult hit(Human *unit);
	virtual void battleLog();
	virtual void action(Human *unit);
	virtual void information();
	virtual void initWeapon();
	virtual double inflictDMG(double damage);
	virtual double heal(double _heal, Human *unit);
};

#endif // __HUMAN_H__