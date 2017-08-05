#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "Human.h"
#include "Warrior.h"
#include "Mage.h"
#include "Priest.h"
///////////////////////////////////////////////////////////
class Human;
///////////////////////////////////////////////////////////
class Factory
{
public:
	virtual Human *create(string name, Team *team) = 0;
	virtual ~Factory();
};

class MageFactory : public Factory
{
public:
	Human *create(string name, Team *team);
};

class WarriorFactory : public Factory
{
public:
	Human *create(string name, Team *team);
};

class PriestFactory : public Factory
{
public:
	Human *create(string name, Team *team);
};

#endif // __FACTORY_H__
