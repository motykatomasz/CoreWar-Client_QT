#include "SettingsWindow.h"
#include "FileSystemDialog.h"
#include <algorithm>
#include <QMessageBox>

SettingsWindow::SettingsWindow(QTcpSocket *socket, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	fwindow = new FileSystemDialog(this);
	connect(ui.fileButton, SIGNAL(clicked()), this, SLOT(showFileDialog()));
	connect(fwindow->ui.selectButton, SIGNAL(clicked()), this, SLOT(showWarrior()));
	connect(ui.verifyButton, SIGNAL(clicked()), this, SLOT(verifyWarrior()));
	connect(ui.createButton, SIGNAL(clicked()), this, SLOT(createSession()));
	connect(ui.WarriorEditor, SIGNAL(textChanged()), this, SLOT(unverify()));
	this->socket = socket;
	this->available_instructions.append("DAT");
	this->available_instructions.append("MOV");
	this->available_instructions.append("ADD");
	this->available_instructions.append("SUB");
	this->available_instructions.append("MUL");
	this->available_instructions.append("DIV");
	this->available_instructions.append("MOD");
	this->available_instructions.append("JMP");
	this->available_instructions.append("JMN");
	this->available_instructions.append("JMZ");
	this->available_instructions.append("DJN");
	this->available_instructions.append("SPL");
	this->available_instructions.append("STL");
	this->available_instructions.append("CMP");
	this->available_instructions.append("SEQ");
	this->available_instructions.append("SNE");
	this->available_instructions.append("NOP");
	this->available_instructions.append("LDP");
	this->available_instructions.append("STP");

	ui.comboCore->addItem("100");
	ui.comboCore->addItem("400");
	ui.comboCore->addItem("2500");
	ui.comboCore->addItem("10000");

	ui.lineCore->setValidator(new QIntValidator(50, 1000, this));
	ui.lineInstruction->setMaxLength(3);
	isVerified = false;

}

void SettingsWindow::showFileDialog() 
{
	
	fwindow->setModal(true);
	fwindow->exec();

}

void SettingsWindow::showWarrior()
{
	ui.WarriorEditor->clear();
	fwindow->hide();
	QString path = fwindow->getPath();
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly))
		QMessageBox::information(0, "info", file.errorString());

	QTextStream in(&file);

	ui.WarriorEditor->setPlainText(in.readAll());
	
}

void SettingsWindow::verifyWarrior()
{
	QString str;
	QMessageBox msg;
	int n = 0;

	if (ui.WarriorEditor->toPlainText() == "")
		str = "Please specify warrior";
	else 
	{
		QString plainTextEditContents = ui.WarriorEditor->toPlainText();
		QStringList lines = plainTextEditContents.split("\n");
	
	
		for (int i = 0; i < lines.size(); i++)
		{
			qDebug() << lines[i];
			verifyLine(lines[i], i + 1, str);
			++n;
		}
		qDebug() << str;

		if (n > ui.comboCore->currentText().toInt() / 2)
		{
			str = "Too many instructions";
		}

		if (str.isEmpty()) {
			str = "Warrior is fine";
			isVerified = true;
		}
	}
	msg.setText(str);
	msg.exec();

}	

void SettingsWindow::verifyLine(QString currentLine, int i, QString& str)
{
	QStringList list = currentLine.split(QRegExp("\\s+"), QString::SkipEmptyParts);
	
	if (std::find(available_instructions.begin(), available_instructions.end(), list[0]) == available_instructions.end())
	{
		str += QStringLiteral("Instruction not available at line: %1 \n").arg(i);		
	}
	else if (!isNumber(list[1]) || !isNumber(list[2]))
	{
		str += QStringLiteral("Wrong arguments at line: %1 \n").arg(i);
	}
	else
	{

	}
}  

void SettingsWindow::hide()
{
	ui.lineCore->clear();
	ui.lineInstruction->clear();
	ui.lineTurns->clear();
	this->close();
}

void SettingsWindow::createSession()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	if (ui.lineTurns->text().isEmpty() || ui.lineInstruction->text().isEmpty() || ui.lineName->text().isEmpty() || ui.WarriorEditor->toPlainText().isEmpty() || ui.lineIP->text().isEmpty())
	{
		QMessageBox msg;
		msg.setText("Please specify all fields.");
		msg.exec();
	}
	else if (!isVerified)
	{
		QMessageBox msg;
		msg.setText("Please verify warrior.");
		msg.exec();

	}
	else {
		out << (qint16)1;
		out << (qint16)ui.comboCore->currentText().toInt();
		//out << (qint16)ui.lineCore->text().toInt();
		out << (qint16)ui.lineTurns->text().toInt();
		out << ui.lineInstruction->text();
		out << ui.WarriorEditor->toPlainText();
		out << ui.lineName->text();

		connectServer();

		socket->write(block);
		hide();
	}
}

void SettingsWindow::connectServer()
{
	QString ip = ui.lineIP->text();
	socket->connectToHost(ip, 9999);
	if (socket->waitForConnected(5000))
	{
		qDebug() << "Connected";
	}
	else
	{
		qDebug() << "Not Connected";
	}


}

bool SettingsWindow::isNumber(QString num)
{
	
	QRegExp a1 = QRegExp("[#@*$-]\\d+");
	QRegExp a2 = QRegExp("\\d+");
	QRegExp a3 = QRegExp("[#@*$]\\-\\d+");

	if (a1.exactMatch(num) || a2.exactMatch(num) || a3.exactMatch(num))
		return true;
	else
		return false;
	/*bool isNumber = true;
	for (QString::const_iterator k = num.begin(); k != num.end(); ++k) {
		isNumber = isNumber && k->isDigit();
	}
	return isNumber;*/
}

void SettingsWindow::unverify()
{
	isVerified = false;
}

SettingsWindow::~SettingsWindow()
{
}