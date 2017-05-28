#pragma once

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include "ui_FileSystemDialog.h"

/**
* @brief FIle System Window
Okno systemu plik�w do wyboru pliku z kodem wojownika.
*/

class FileSystemDialog : public QDialog
{
	Q_OBJECT

public:
	FileSystemDialog(QWidget *parent = Q_NULLPTR);
	~FileSystemDialog();
	Ui::FileSystemDialog ui;
	
	public slots:
	/**
	* @brief Metoda zwracaj�ca �cie�k� do pliku z wojownikiem
	*/
	QString getPath();					

private:

	QString WarriorFile;				//��ie�ka do pliku z instrukcjami wojownika
	QFileSystemModel *dirmodel;			//obiekt do wy�wietlania drzewa folder�w
	QFileSystemModel *filemodel;		//obiekt do wy�wietlania plik�w w folderze

	private slots:
	/**
	* @brief Metoda wy�wietlaj�ca pliki w wybranym folderze
	*/
	void showFiles(const QModelIndex &index);

	/**
	* @brief Metoda wczytuj�ca �cie�ke wybranego pliku
	*/
	void setPath(const QModelIndex &index);


};
