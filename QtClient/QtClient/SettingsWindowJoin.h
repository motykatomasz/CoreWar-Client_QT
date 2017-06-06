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
	QVector<QString> available_instructions;		//kolekcja dost�pnych instrukcji
	QTcpSocket* socket;						//gniazdo tcp do komunikacji z serwerem
	bool isVerified;

	/**
	* @brief Metoda zestawiaj�ca po��czenie z serwerem
	*/
	void connectServer();

	private slots:

	/**
	* @brief Metoda wczytuj�ca parametry do do��czenia do sesji i wysy�aj�ca polecenie na serwer
	*/
	void joinSession();

	/**
	* @brief Metoda wy�wietlaj�ca okno systemu plik�w
	*/
	void showFileDialog();

	/**
	* @brief Metoda wczytuj�ca kod wojownika z pliku do edytora
	*/
	void showWarrior();

	/**
	* @brief Metoda weryfikuj�ca czy instrukcje wojownika s� poprawne
	*/
	void verifyWarrior();

	/**
	* @brief Metoda weryfikuj�ca pojedyncz� instrukcj� oraz jej argumenty
	* \param currentLine aktualna linijka kodu wojownika
	* \param i numer aktualnej linijki kodu wojownika
	* \param str komunikat o b�edach do modyfikacji
	*/
	void verifyLine(QString currentLine, int i, QString& str);

	/**
	* @brief Metoda sprawdzaj�ca czy argument instrukcji jest liczb�
	* \param num argument do weyfikacji
	* \return Czy argument poprawny
	*/
	bool isNumber(QString num);

	/**
	* @brief Metoda zamykaj�ca okno ustawie�
	*/
	void hide();

	/**
	* @brief Metoda 
	*/
	void unverify();
};
