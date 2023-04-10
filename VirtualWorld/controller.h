#pragma once
#include "shapemanager.h"
#include <QVector>
#include <QRadioButton>
#include <QPointF>

class ControllerAdd
{
	ShapeManager* shapeManager;
public:
	ControllerAdd(ShapeManager* = nullptr);
	void control(QVector<QRadioButton*>);
};

class ControllerMoveShape
{
	ShapeManager* shapeManager;
public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};
