#include "shapemanager.h"


ShapeManager::ShapeManager() : Observable(), selected(nullptr)
{}

void ShapeManager::add(Shape* shape)
{
	if (shape == nullptr) return;

	shapes.append(shape);
	notifyObserver();
}


void ShapeManager::moveShape(QPointF pos)
{
	if (selected == nullptr) return;

	selected->pos = pos;
}

bool ShapeManager::selectShape(int id)
{
	bool isPresent = false;
	if (selected != nullptr && selected->type() == "Group") {
		for (Shape* sh : selected->getShapes()) {
			if (sh->id == id) {
				isPresent = true;
			}
		}
	}

	if (isPresent == false) {
		selected = nullptr;
		for (Shape* shape : shapes)
		{
			if (shape->id == id)
			{
				selected = shape;
				return true;
			}
		}

		return false;
	}
}

bool ShapeManager::addSelectShape(int id)
{
	for (Shape* shape : shapes)
	{
		if (shape->id == id)
		{
			if (selected != nullptr && selected->type() == "Group") {
				selected->add(shape);
			}
			else {
				if (selected != nullptr) {
					Shape* now = new Group();
					now->add(selected);
					now->add(shape);
					selected = now;
				}
				else {
					selected = shape;
				}
			}
			return true;
		}
	}

	return false;
}

Shape* ShapeManager::getShape(int id) {
	for (Shape* shape : shapes)
	{
		if (shape->id == id)
		{
			return shape;
		}
	}
	return nullptr;
}
