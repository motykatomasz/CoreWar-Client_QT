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
	Okno pocz¹tkowe aplikacji klienckiej.
	St¹d mamy mo¿liwoœæ ustawienia parametrów rozgrywki, edycji naszego wojownika oraz rozpoczêcia rozgrywki.
*/

class QtClient : public QMainWindow
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtClientClass ui;
	SettingsWindow *swindow;	/*!<okno opcji tworzenia sesji*/
	SettingsWindowJoin * jwindow; //okno opcji do³¹czania do sesji
	GameWindow *gwindow;		//okno gry
	QTcpSocket *_pSocket;		//gniazdo do komunikacji
	Settings *settings;			//ustawienia gry
	QMap<QString, QColor>* instructionColors; //s³ownik mapuj¹cy instrukcjê na przypisany jej kolor

	QTimer *timer;
	private slots:

	

	/**
	* @brief Metoda inicjuj¹ca po³¹czenie TCP z serwerem	
	*/
	void connectTcp();

	/**
	* @brief Metoda wyœwietlaj¹ca okno opcji stworzenia nowej sesji
	*/
	void showSettingsDialog();

	/**
	* @brief Metoda wyœwietlaj¹ca okno opcji do³¹czenia do sesji
	*/
	void showJoinDialog();

	/**
	* @brief Metoda wyœwiwietlaj¹ca okno gry
	*
	* \param size rozmiar planszy
	* \param color domyœlny kolor komórek planszy
	*/
	void showGameWindow(int size, const QColor& color);

	/**
	* @brief Metoda do czytania danych od serwera
	*/
	void readTcpData();
	
	/**
	* @brief Metoda do wczytywania wojowników na planszê
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
