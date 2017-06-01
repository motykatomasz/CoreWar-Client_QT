#pragma once

#include <QDialog>
#include "ui_SettingsWindowJoin.h"
#include "FileSystemDialog.h"
#include "Settings.h"
#include <QTcpSocket>

class SettingsWindowJoin : public QDialog
{
	Q_OBJECT

public:
	SettingsWindowJoin(QTcpSocket* socket, QWidget *parent = Q_NULLPTR);
	~SettingsWindowJoin();
	FileSystemDialog *fwindow;

private:
	Ui::SettingsWindowJoin ui;
	QVector<QString> available_instructions;		//kolekcja dostêpnych instrukcji
	QTcpSocket* socket;						//gniazdo tcp do komunikacji z serwerem
	bool isVerified;

	private slots:

	/**
	* @brief Metoda wczytuj¹ca parametry do do³¹czenia do sesji i wysy³aj¹ca polecenie na serwer
	*/
	void joinSession();

	/**
	* @brief Metoda wyœwietlaj¹ca okno systemu plików
	*/
	void showFileDialog();

	/**
	* @brief Metoda wczytuj¹ca kod wojownika z pliku do edytora
	*/
	void showWarrior();

	/**
	* @brief Metoda weryfikuj¹ca czy instrukcje wojownika s¹ poprawne
	*/
	void verifyWarrior();

	/**
	* @brief Metoda weryfikuj¹ca pojedyncz¹ instrukcjê oraz jej argumenty
	*/
	void verifyLine(QString currentLine, int i, QString str);

	/**
	* @brief Metoda sprawdzaj¹ca czy argument instrukcji jest liczb¹
	*/
	bool isNumber(QString num);

	/**
	* @brief Metoda zamykaj¹ca okno ustawieñ
	*/
	void hide();

	void unverify();
};
