#pragma once
#include <QObject>

class Settings
{
public:
	Settings();
	~Settings();
	int getCoreSize();
	void setCoreSize(int size);

	int getTurns();
	void setTurns(int turns);

	QString getWarrior();
	void setWarrior(QString war);

	QString getInstruction();
	void setInstruction(QString ins);

private:
	int coreSize;
	int turns;
	QString warrior;
	QString defaultIns;
	



};
