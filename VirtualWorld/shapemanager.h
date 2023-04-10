#pragma once

#include "shape.h"
#include "observer.h"
#include <QVector>
#include <QPointF>

class ShapeManager : public Observable
{
private:
	QVector<Shape*> shapes;
	Shape* selected = nullptr;

public:
	ShapeManager();
	void add(Shape*);
	void moveShape(QPointF);

	bool selectShape(int);
	bool addSelectShape(int);
	Shape* getSelectedShape() { return this->selected; }
	Shape* getShape(int id);

    const QVector<Shape*>& getShapes() const {return shapes;}
};

