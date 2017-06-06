#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtClient.h"
#include <QTcpSocket>
#include "SettingsWindow.h"
#include "GameWindow.h"
#include "Settings.h"
#include "SettingsWindowJoin.h"

/**
* @brief Starting Window
	Okno pocz�tkowe aplikacji klienckiej.
	St�d mamy mo�liwo�� ustawienia parametr�w rozgrywki, edycji naszego wojownika oraz rozpocz�cia rozgrywki.
*/

class QtClient : public QMainWindow
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtClientClass ui;
	SettingsWindow *swindow;	/*!<okno opcji tworzenia sesji*/
	SettingsWindowJoin * jwindow; //okno opcji do��czania do sesji
	GameWindow *gwindow;		//okno gry
	QTcpSocket *_pSocket;		//gniazdo do komunikacji
	Settings *settings;			//ustawienia gry
	QMap<QString, QColor>* instructionColors; //s�ownik mapuj�cy instrukcj� na przypisany jej kolor

	QTimer *timer;
	private slots:

	

	/**
	* @brief Metoda inicjuj�ca po��czenie TCP z serwerem	
	*/
	void connectTcp();

	/**
	* @brief Metoda wy�wietlaj�ca okno opcji stworzenia nowej sesji
	*/
	void showSettingsDialog();

	/**
	* @brief Metoda wy�wietlaj�ca okno opcji do��czenia do sesji
	*/
	void showJoinDialog();

	/**
	* @brief Metoda wy�wiwietlaj�ca okno gry
	*
	* \param size rozmiar planszy
	* \param color domy�lny kolor kom�rek planszy
	*/
	void showGameWindow(int size, const QColor& color);

	/**
	* @brief Metoda do czytania danych od serwera
	*/
	void readTcpData();
	
	/**
	* @brief Metoda do wczytywania wojownik�w na plansz�
	*
	* \param warrior kod wojownika
	* \param core rozmiar planszy
	* \param front punkt startowy wojownika
	*/
	void putWarriorOnBoard(QString warrior, int core, bool front);

	void test();

	public slots:

	void exitGame();
};
