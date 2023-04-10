#include "ShapeFactory.h"

ShapeFactory::ShapeFactory() {
}

Shape* ShapeFactory::createShape(QVector <QRadioButton*> buttons) {
	for (QRadioButton* button : buttons) {
		if (button->isChecked()) {
			QString test = button->text().toLower().trimmed();
			srand(time(NULL));

			if (test == "circle") {
				return new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 10);
			}
			else if (test == "square") {
				return new Square(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 +10);
			}
			else if (test == "rectangle") {
				return new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 10, std::rand() % 100 + 10);
			}
			else {
				return nullptr;
			}
		}
	}
}