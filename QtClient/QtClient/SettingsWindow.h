#pragma once
#include <QDialog>
#include "ui_SettingsWindow.h"
#include "FileSystemDialog.h"
#include "Settings.h"
#include <QTcpSocket>




/**
* @brief Settings Window
Okno wyboru ustawie� aplikacji klienckiej.
W tym oknie mamy mo�liwo�� doboru parametr�w rozgrywki(ilo�� tur, nominalna instrukcja jak� jest wype�niony rdze�, wielko�� rdzenia) oraz edycji wojownika
*/

class SettingsWindow : public QDialog
{
	Q_OBJECT

public:
	SettingsWindow(QTcpSocket *socket, QWidget *parent = Q_NULLPTR);
	~SettingsWindow();
	FileSystemDialog *fwindow; //okno systemu plik�w do wczytania kodu wojownika z pliku
	

private:
	Ui::SettingsWindow ui;
	QVector<QString> available_instructions;	//kolekcja dost�pnych instrukcji
	QTcpSocket* socket;						//gniazdo tcp do komunikacji z serwerem
	bool isVerified;

	/**
	* @brief Metoda zestawiaj�ca po��czenie z serwerem
	*/
	void connectServer();

	/**
	* @brief Metoda sprawdzaj�ca czy argument instrukcji jest liczb�
	* \param num argument do weyfikacji
	* \return Czy argument poprawny
	*/
	bool isNumber(QString num);

	private slots:
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
	* @brief Metoda zamykaj�ca okno ustawie�
	*/
	void hide();

	/**
	* @brief Metoda wczytuj�ca dane do utworzenia serwera i wysy�aj�ca zapytanie na serwer
	*/
	void createSession();

	/**
	* @brief Metoda zmieniaj�ca stan weryfikacji wojownika
	*/
	void unverify();

};
