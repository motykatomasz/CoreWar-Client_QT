
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

class InstructionItem : public QGraphicsItem
{
public:
	InstructionItem(int x, int y, int size_x, int size_y, const QColor& color);
	~InstructionItem();




	/**
	* @brief Metoda rysuj�ca pojedyncz� kom�rk� rdzenia
	*/
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	/**
	* @brief Metoda zmieniaj�ca kolor kom�rki
	*/
	void ChangeColor(const QColor& color);

	/**
	* @brief Metoda zwracaj�ca prostok�t do pomalowania
	*/
	QRectF boundingRect() const;

private:
	int instruction_height;			//wysoko�� kom�rki
	int instruction_width;			//szeroko�� kom�rki	
	QBrush *color;					//kolor kom�rki

};



