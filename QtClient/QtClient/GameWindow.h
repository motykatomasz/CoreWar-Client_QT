#pragma once

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include "ui_GameWindow.h"
#include "InstructionItem.h"

class GameWindow : public QWidget
{
	Q_OBJECT

public:
	GameWindow(int coreSize, const QColor& color, QWidget *parent = Q_NULLPTR);

	void Change_Instruction(int address, const QColor& color);
	~GameWindow();

private:
	Ui::GameWindow ui;
	QGraphicsScene *scene;

	
	int instruction_height;			//wysoko�� kom�rki pami�ci
	int instruction_width;			//szeroko�� kom�rki pami�ci
	int coreSize;					//wielko�� rdzenia
	std::vector<InstructionItem*> instructions;		//kolekcja przechowuj�ca wszystkie kom�rki rdzenia

	/**
	* @brief Metoda wyliczaj�ca wielko�� wy�wietlanej kom�rki pami�ci
	*/
	void Set_Instruction_Size(const int coreSize);

	/**
	* @brief Metoda tworz�ca rdze� i wy�wietlaj�ca kom�rki pami�ci
	*/
	void Create_Board(const int coreSize, const QColor& color);


};
