#pragma once
#include <QPointF>
#include <QGraphicsItem>

struct Dimension {
	double height;
	double width;
};

class Shape {
public:
	QPointF pos;
	int id;
	static int current_id; // added
	virtual QGraphicsItem* getGraphicsItem() = 0;
	virtual QString type() = 0;
	virtual Dimension getDimension() = 0;
	virtual void add(Shape*) {};
	virtual QVector<Shape*> getShapes() { return QVector<Shape*>(); }
};

class Circle : public Shape
{
private:
	double radius;
public: 
	Circle();
	Circle(QPointF, double);

    QGraphicsItem* getGraphicsItem() override;
    QString type() override;
	Dimension getDimension() override;
};

class Square : public Shape
{
private:
	double side;
public:

	Square();
	Square(QPointF, double);

	QGraphicsItem* getGraphicsItem() override;
	QString type() override;
	Dimension getDimension() override;
};

class Rectangle : public Shape
{
private:
	double height;
	double width;
public:

	Rectangle();
	Rectangle(QPointF, double, double);

	QGraphicsItem* getGraphicsItem() override;
	QString type() override;
	Dimension getDimension() override;
};

class Group : public Shape
{
private:
	QVector<Shape*> shapes;
	void changed();
	Dimension dim;
public:

	Group();
	Group(QPointF);

	void add(Shape*);
	QVector<Shape*> getShapes() { return shapes; }
	QGraphicsItem* getGraphicsItem() override;
	QString type() override;
	Dimension getDimension() override;
};