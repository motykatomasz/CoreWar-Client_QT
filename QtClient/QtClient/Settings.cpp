#include "Settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

int Settings::getCoreSize()
{
	return this->coreSize;
}

void Settings::setCoreSize(int size)
{
	this->coreSize = size;
}

int Settings::getTurns()
{
	return this->turns;
}

void Settings::setTurns(int turns)
{
	this->turns = turns;
}

QString Settings::getWarrior()
{
	return this->warrior;
}

void Settings::setWarrior(QString war)
{
	this->warrior = war;
}

QString Settings::getInstruction()
{
	return this->defaultIns;
}

void Settings::setInstruction(QString ins)
{
	this->defaultIns = ins;
}
