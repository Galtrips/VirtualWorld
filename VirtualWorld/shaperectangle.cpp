#include "shape.h"
#include <QGraphicsRectItem>

Rectangle::Rectangle() : Shape()
{
	this->id = current_id++;
	pos = QPointF(-1, -1);
	width = 0.;
	height = 0.;
}

Rectangle::Rectangle(QPointF p, double height, double width) : Shape()
{
	this->width = width;
	this->height = height;
	this->id = current_id++;
	pos = p;
}


QGraphicsItem* Rectangle::getGraphicsItem()
{
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - this->width / 2, pos.y() - height / 2, width, height);
	item->setData(0, id);
	return item;
}


QString Rectangle::type()
{
	return "Rectangle";
}

Dimension Rectangle::getDimension() {
	Dimension dim;
	dim.height = height;
	dim.width = width;
	return dim;
}
