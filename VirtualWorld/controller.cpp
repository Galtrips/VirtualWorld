#include "controller.h"
#include "shapemanager.h"
#include "ShapeFactory.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <QMessageBox>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(QVector <QRadioButton*> buttons)
{
	if (shapeManager == nullptr) return;

	Shape* shape = ShapeFactory::createShape(buttons);

	if (shape != nullptr) {

		shapeManager->add(shape);
	}
	else {
		QMessageBox::warning(nullptr, "Add Shape", "La forme selectionnee n'existe pas !");
	}
	// Add Shape
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
	if (shapeManager == nullptr) return;

	// Move Shape
	for (QGraphicsItem* item : items)
	{
		QVariant variant = item->data(0);
		int id = variant.toInt();

		if (shapeManager->getSelectedShape()->type() != "Group") {
			bool selected = shapeManager->selectShape(id);
			if (selected)
			{
				QRectF rect = item->boundingRect();
				shapeManager->moveShape(item->scenePos() + rect.center());
			}
		}
	}

	shapeManager->notifyObserver();
}
