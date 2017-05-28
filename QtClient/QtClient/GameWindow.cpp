#include "GameWindow.h"
#include <math.h>  
#include <memory>




GameWindow::GameWindow(int coreSize, const QColor& color, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	scene = new QGraphicsScene(this);	
	ui.graphicsView->setScene(scene);

	scene->setSceneRect(0, 0, 1200, 600);
	ui.graphicsView->setRenderHint(QPainter::Antialiasing);

	/*QLineF topLine(scene->sceneRect().topLeft(),
		scene->sceneRect().topRight());
	QLineF leftLine(scene->sceneRect().topLeft(),
		scene->sceneRect().bottomLeft());
	QLineF rightLine(scene->sceneRect().topRight(),
		scene->sceneRect().bottomRight());
	QLineF bottomLine(scene->sceneRect().bottomLeft(),
		scene->sceneRect().bottomRight());

	QPen myPen = QPen(Qt::red);

	scene->addLine(topLine, myPen);
	scene->addLine(leftLine, myPen);
	scene->addLine(rightLine, myPen);
	scene->addLine(bottomLine, myPen);*/

	Set_Instruction_Size(coreSize);
	Create_Board(coreSize, color);
	//this->instructions[0]->ChangeColor("black");
	
}

//do zrobienia jak zczytac rozmiar okna
void GameWindow::Set_Instruction_Size(const int core)
{
	int field = 1200 * 600;
	this->instruction_height = floor(sqrt(field / (2 * core)));
	this->instruction_width = 2 * this->instruction_height;

}

void GameWindow::Create_Board(const int coreSiz, const QColor& color)
{
	int row = floor(1200 / this->instruction_width);
	int column = floor(600 / this->instruction_height);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			InstructionItem *item = new InstructionItem(j*instruction_width, i*instruction_height, instruction_width, instruction_height, color);

			this->instructions.push_back(item);
			this->scene->addItem(item);
		}
	}
}

void GameWindow::Change_Instruction(int address, const QColor & color)
{
	this->instructions[address]->ChangeColor(color);
}

GameWindow::~GameWindow()
{
	delete scene;
	instructions.clear();
}
