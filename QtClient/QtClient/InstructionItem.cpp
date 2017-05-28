#include "InstructionItem.h"
#include <qdebug.h>



InstructionItem::InstructionItem(int x, int y, int size_x, int size_y, const QColor& color)
{
	this->instruction_height = size_y;
	this->instruction_width = size_x;
	setPos(mapToParent(x, y));
	this->color = new QBrush(color);
	update();
}

QRectF InstructionItem::boundingRect() const
{
	return QRect(0, 0, this->instruction_width, this->instruction_height);
}

void InstructionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QRectF rect = boundingRect();
	QPen pen(Qt::black, 3);
	painter->setPen(pen);
	painter->drawRect(rect);
	painter->fillRect(rect, this->color->color());

}

void InstructionItem::ChangeColor(const QColor& color)
{	
	this->color->setColor(color);
	update();
}

InstructionItem::~InstructionItem()
{
	delete color;
}
