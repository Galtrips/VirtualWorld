#include "shape.h"
#include <QGraphicsRectItem>

Group::Group() : Shape()
{
	this->id = current_id++;
	pos = QPointF(-1, -1);
	this->dim.height = 0;
	this->dim.width = 0;
}

Group::Group(QPointF p) : Shape()
{
	this->id = current_id++;
	pos = p;
	this->dim.height = 0;
	this->dim.width = 0;
}


QGraphicsItem* Group::getGraphicsItem()
{
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - dim.width / 2, pos.y() - dim.height / 2, dim.width, dim.height);
	item->setData(0, id);
	return item;
}

QString Group::type()
{
	return "Group";
}

Dimension Group::getDimension() {
	return this->dim;
}

void Group::add(Shape* shape)
{
	if (shape == nullptr) return;

	bool present = false;
	for (auto forme : this->shapes) {
		if (shape->id == forme->id) {
			present = true;
		}
	}

	if (present == false) {
		shapes.append(shape);
		this->changed();
	}
}

void Group::changed() {

	QPointF pos = shapes[0]->pos;
	Dimension firstShape = shapes[0]->getDimension();

	QVector<Dimension> dims;
	for (Shape* shape : this->shapes) {
		dims.append(shape->getDimension());
	}

	double minX = pos.x() - (firstShape.width / 2);
	double maxX = pos.x() + (firstShape.width / 2);

	double minY = pos.y() - (firstShape.height / 2);
	double maxY = pos.y() + (firstShape.height / 2);

	for (Shape* shape : this->shapes) {

		QPointF posShape = shape->pos;
		Dimension dimShape = shape->getDimension();

		double currentXmin = posShape.x() - (dimShape.width / 2);
		double currentYmin = posShape.y() - (dimShape.height / 2);
		
		double currentXmax = posShape.x() + (dimShape.width / 2);
		double currentYmax = posShape.y() + (dimShape.height / 2);

		for (Dimension currentDim : dims) {
			if (currentXmin > posShape.x() - (currentDim.width / 2)) {
				currentXmin = posShape.x() - (currentDim.width / 2);
			}

			if (currentXmax < posShape.x() + (currentDim.width / 2)) {
				currentXmax = posShape.x() + (currentDim.width / 2);
			}

			if (currentYmin > posShape.y() - (currentDim.height / 2)) {
				currentYmin = posShape.y() - (currentDim.height / 2);
			}

			if (currentYmax < posShape.y() + (currentDim.height / 2)) {
				currentYmax = posShape.y() + (currentDim.height / 2);
			}
		}
		
		if (currentXmin < minX) {
			minX = currentXmin;
		}
		if (currentXmax > maxX) {
			maxX = currentXmax;
		}

		if (currentYmin < minY) {
			minY = currentYmin;
		}
		if (currentYmax > maxY) {
			maxY = currentYmax;
		}
	}
	this->dim.height = maxY - minY;
	this->dim.width = maxX - minX;

	double midX = (maxX + minX) / 2;
	double midY = (maxY + minY) / 2;

	this->pos = QPointF(midX, midY);
}