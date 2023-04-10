#include "shape.h"
#include <QGraphicsRectItem>

Square::Square() : Shape()
{
	this->id = current_id++;
	pos = QPointF(-1, -1);
	side = 0.;
}

Square::Square(QPointF p, double size) : Shape(), side(size)
{
	this->id = current_id++;
	pos = p;
}


QGraphicsItem* Square::getGraphicsItem()
{
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - this->side/2, pos.y() - side/2, side, side);
	item->setData(0, id);
	return item;
}


QString Square::type()
{
	return "Square";
}


Dimension Square::getDimension() {
	Dimension dim;
	dim.height = side;
	dim.width = side;
	return dim;
}

