#pragma once
#include "shape.h"
#include "shapemanager.h"
#include <QRadioButton> 

class ShapeFactory
{
private:
	QVector <QRadioButton*> buttons;
public:
	ShapeFactory();
	static Shape* createShape(QVector <QRadioButton*> buttons);
};

