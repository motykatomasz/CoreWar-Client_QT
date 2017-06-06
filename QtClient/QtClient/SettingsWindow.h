#pragma once
#include <QDialog>
#include "ui_SettingsWindow.h"
#include "FileSystemDialog.h"
#include "Settings.h"
#include <QTcpSocket>




/**
* @brief Settings Window
Okno wyboru ustawieñ aplikacji klienckiej.
W tym oknie mamy mo¿liwoœæ doboru parametrów rozgrywki(iloœæ tur, nominalna instrukcja jak¹ jest wype³niony rdzeñ, wielkoœæ rdzenia) oraz edycji wojownika
*/

class SettingsWindow : public QDialog
{
	Q_OBJECT

public:
	SettingsWindow(QTcpSocket *socket, QWidget *parent = Q_NULLPTR);
	~SettingsWindow();
	FileSystemDialog *fwindow; //okno systemu plików do wczytania kodu wojownika z pliku
	

private:
	Ui::SettingsWindow ui;
	QVector<QString> available_instructions;	//kolekcja dostêpnych instrukcji
	QTcpSocket* socket;						//gniazdo tcp do komunikacji z serwerem
	bool isVerified;

	/**
	* @brief Metoda zestawiaj¹ca po³¹czenie z serwerem
	*/
	void connectServer();

	/**
	* @brief Metoda sprawdzaj¹ca czy argument instrukcji jest liczb¹
	* \param num argument do weyfikacji
	* \return Czy argument poprawny
	*/
	bool isNumber(QString num);

	private slots:
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
	* \param currentLine aktualna linijka kodu wojownika
	* \param i numer aktualnej linijki kodu wojownika
	* \param str komunikat o b³edach do modyfikacji
	*/
	void verifyLine(QString currentLine, int i, QString& str);

	/**
	* @brief Metoda zamykaj¹ca okno ustawieñ
	*/
	void hide();

	/**
	* @brief Metoda wczytuj¹ca dane do utworzenia serwera i wysy³aj¹ca zapytanie na serwer
	*/
	void createSession();

	/**
	* @brief Metoda zmieniaj¹ca stan weryfikacji wojownika
	*/
	void unverify();

};
