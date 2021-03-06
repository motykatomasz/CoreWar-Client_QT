#include "QtClient.h"
#include <QMessageBox>

QtClient::QtClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	settings = new Settings();
	_pSocket = new QTcpSocket(this);
	swindow = new SettingsWindow(_pSocket,this);	
	jwindow = new SettingsWindowJoin(_pSocket, this);
	connect(_pSocket, SIGNAL(readyRead()), this, SLOT(readTcpData()));
	connect(ui.joinButton, SIGNAL(clicked()),this, SLOT(showJoinDialog()));
	connect(ui.createButton, SIGNAL(clicked()), this, SLOT(showSettingsDialog()));
	instructionColors = new QMap<QString, QColor>();
	instructionColors->insert("DAT", "red");
	instructionColors->insert("MOV", "green");
	instructionColors->insert("ADD", "blue");
	instructionColors->insert("SUB", QColor(1, 1, 1));
	instructionColors->insert("MUL", QColor(10, 10, 10));
	instructionColors->insert("DIV", QColor(20, 20, 20));
	instructionColors->insert("MOD", QColor(30, 30, 30));
	instructionColors->insert("JMP", QColor(40, 40, 40));
	instructionColors->insert("JMN", QColor(50, 50, 50));
	instructionColors->insert("JMZ", QColor(60, 60, 60));
	instructionColors->insert("DJN", QColor(70, 70, 70));
	instructionColors->insert("SPL", QColor(80, 80, 80));
	instructionColors->insert("STL", QColor(90, 90, 90));
	instructionColors->insert("CMP", QColor(100, 100, 100));
	instructionColors->insert("SEQ", QColor(110, 110, 110));
	instructionColors->insert("SNE", QColor(120, 120, 120));
	instructionColors->insert("NOP", QColor(130, 130, 130));
	instructionColors->insert("LDP", QColor(140, 140, 140));
	instructionColors->insert("STP", QColor(150, 150, 150));


	connectTcp();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(exitGame()));

	
}




void QtClient::connectTcp()
{
	/*_pSocket->connectToHost("127.0.0.1", 9999);
	if (_pSocket->waitForConnected(5000)) 
	{
		qDebug() << "Connected";
	}
	else
	{
		qDebug() << "Not Connected";
	}*/

}

void QtClient::showSettingsDialog()
{
	swindow->setModal(true);
	swindow->exec();

}

void QtClient::showJoinDialog()
{
	jwindow->setModal(true);
	jwindow->exec();
}

void QtClient::showGameWindow(int size, const QColor& color)
{
	gwindow = new GameWindow(size, color);
	gwindow->show();

}

void QtClient::readTcpData()
{
	QDataStream in(_pSocket);
	quint16 msg_type;;
	in.setVersion(QDataStream::Qt_4_0);

	in >> msg_type;
	qDebug() << msg_type;

	//stworzenie pocz�tkowej planszy
	if (msg_type == 3) 
	{	
		qint16 core;
		QString ins;
		QString warrior1;
		QString warrior2;

		in >> core;
		in >> warrior1;
		in >> warrior2;
		in >> ins;



		showGameWindow(core, instructionColors->value(ins));
		putWarriorOnBoard(warrior1, core, true);
		putWarriorOnBoard(warrior1, core, false);

	}

	//aktualizacja planszy
	else if (msg_type == 4)
	{
		qint16 addr;
		QString ins;

		in >> addr;
		in >> ins;

		gwindow->Change_Instruction(addr, instructionColors->value(ins));

	}

	//wynik rozgrywki
	else if (msg_type == 5)
	{
		QString outcome;

		in >> outcome;
		qDebug() << outcome;

		delete gwindow;
		
		QMessageBox msg;
		msg.setText(outcome);
		msg.exec();

	}

	//komunikaty o b��dach
	else if (msg_type == 6)
	{
		QString err;

		in >> err;

		QMessageBox msg;
		msg.setText(err);
		msg.exec();

	}


}

void QtClient::putWarriorOnBoard(QString warrior, int core, bool front)
{
	QStringList lines = warrior.split("\n");
	for (int i = 0; i < lines.size(); i++)
	{
		QStringList list = lines[i].split(QRegExp("\\s+"), QString::SkipEmptyParts);
		if (front)
		{
			gwindow->Change_Instruction(i, instructionColors->value(list[0]));
		}
		else
		{
			gwindow->Change_Instruction(core/2, instructionColors->value(list[0]));
		}		
	}
}

void QtClient::test()
{
	
	showGameWindow(10000, "blue");
	gwindow->Change_Instruction(1, "green");


}

void QtClient::exitGame()
{
	qDebug() << "abc";
	delete gwindow;
	timer->stop();

}




