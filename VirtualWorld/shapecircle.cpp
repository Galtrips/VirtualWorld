#include "shape.h"
#include <QGraphicsEllipseItem>

int Shape::current_id; // added

Circle::Circle() : Shape()
{
	this->id = current_id++;
	pos = QPointF(-1, -1);
	radius = 0.;
}

Circle::Circle(QPointF p, double r) : Shape(), radius(r)
{
	this->id = current_id++;
	pos = p;
}


QGraphicsItem* Circle::getGraphicsItem() 
{
	QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
	item->setData(0,id);
	return item;
}


QString Circle::type()
{
	return "Circle";
}


Dimension Circle::getDimension() {
	Dimension dim;
	dim.height = radius * 2;
	dim.width = radius * 2;
	return dim;
}
