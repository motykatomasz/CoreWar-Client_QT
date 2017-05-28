#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtClient.h"
#include <QTcpSocket>
#include "addressbook.pb.h"
#include "SettingsWindow.h"
#include "GameWindow.h"
#include "Settings.h"
#include "SettingsWindowJoin.h"

/**
* @brief Starting Window
	Okno początkowe aplikacji klienckiej.
	Stąd mamy możliwość ustawienia parametrów rozgrywki, edycji naszego wojownika oraz rozpoczęcia rozgrywki.
*/

class QtClient : public QMainWindow
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtClientClass ui;
	SettingsWindow *swindow;	//okno opcji tworzenia sesji
	SettingsWindowJoin * jwindow; //okno opcji dołączania do sesji
	GameWindow *gwindow;		//okno gry
	QTcpSocket *_pSocket;		//gniazdo do komunikacji
	Settings *settings;			//ustawienia gry
	QMap<QString, QString>* instructionColors; //słownik mapujący instrukcję na przypisany jej kolor

	QTimer *timer;
	private slots:

	

	/**
	* @brief Metoda inicjująca połączenie TCP z serwerem	
	*/
	void connectTcp();

	/**
	* @brief Metoda wyświetlająca okno opcji stworzenia nowej sesji
	*/
	void showSettingsDialog();

	/**
	* @brief Metoda wyświetlająca okno opcji dołączenia do sesji
	*/
	void showJoinDialog();

	/**
	* @brief Metoda wyświwietlająca okno gry
	*/
	void showGameWindow(int size, const QColor& color);

	/**
	* @brief Metoda do czytania danych od serwera
	*/
	void readTcpData();
	
	/**
	* @brief Metoda do wczytywania wojowników na planszę
	*/
	void putWarriorOnBoard(QString warrior, int core, bool front);

	void test();

	public slots:

	void exitGame();
};
