#pragma once
///////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////
class Human
{
private:
	std::string Name;
	unsigned id		= 0;
	double health	= 0.0F;
	Team *team		= nullptr;
	Weapon *weapon	= nullptr;
public:
	Human(std::string name, double from, double to, Team *team);
	~Human();
	const bool isAlive();
	const double getHP();
	bool hasWeapon();
	const unsigned getID();
	void dropWeapon();
	void getTeamName();
	void setID(const unsigned &id_);
	const std::string &getName();
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