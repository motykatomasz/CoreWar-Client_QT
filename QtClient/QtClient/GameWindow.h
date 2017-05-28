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

	
	int instruction_height;			//wysokoœæ komórki pamiêci
	int instruction_width;			//szerokoœæ komórki pamiêci
	int coreSize;					//wielkoœæ rdzenia
	std::vector<InstructionItem*> instructions;		//kolekcja przechowuj¹ca wszystkie komórki rdzenia

	/**
	* @brief Metoda wyliczaj¹ca wielkoœæ wyœwietlanej komórki pamiêci
	*/
	void Set_Instruction_Size(const int coreSize);

	/**
	* @brief Metoda tworz¹ca rdzeñ i wyœwietlaj¹ca komórki pamiêci
	*/
	void Create_Board(const int coreSize, const QColor& color);


};
