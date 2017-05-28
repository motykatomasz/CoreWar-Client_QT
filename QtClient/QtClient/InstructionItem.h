
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

class InstructionItem : public QGraphicsItem
{
public:
	InstructionItem(int x, int y, int size_x, int size_y, const QColor& color);
	~InstructionItem();




	/**
	* @brief Metoda rysuj¹ca pojedyncz¹ komórkê rdzenia
	*/
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	/**
	* @brief Metoda zmieniaj¹ca kolor komórki
	*/
	void ChangeColor(const QColor& color);

	/**
	* @brief Metoda zwracaj¹ca prostok¹t do pomalowania
	*/
	QRectF boundingRect() const;

private:
	int instruction_height;			//wysokoœæ komórki
	int instruction_width;			//szerokoœæ komórki	
	QBrush *color;					//kolor komórki

};



