#pragma once

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include "ui_FileSystemDialog.h"

/**
* @brief FIle System Window
Okno systemu plików do wyboru pliku z kodem wojownika.
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
	* @brief Metoda zwracaj¹ca œcie¿kê do pliku z wojownikiem
	*/
	QString getPath();					

private:

	QString WarriorFile;				//œæie¿ka do pliku z instrukcjami wojownika
	QFileSystemModel *dirmodel;			//obiekt do wyœwietlania drzewa folderów
	QFileSystemModel *filemodel;		//obiekt do wyœwietlania plików w folderze

	private slots:
	/**
	* @brief Metoda wyœwietlaj¹ca pliki w wybranym folderze
	*/
	void showFiles(const QModelIndex &index);

	/**
	* @brief Metoda wczytuj¹ca œcie¿ke wybranego pliku
	*/
	void setPath(const QModelIndex &index);


};
