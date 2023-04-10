#include "view.h"
#include "shape.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGuiApplication>

PaintView::PaintView( ShapeManager* sm) : QGraphicsScene(), Observer(), shapeManager(sm)
{
}

void PaintView::drawForeground(QPainter* painter, const QRectF& rect)
{
	if (toolbox.isEmpty()) return;

	QGraphicsView* gv = (QGraphicsView*)this->parent();
	
	QPointF p1 = gv->mapToScene(QPoint(10, 10));
	
	painter->save();
	
	painter->setBrush(QBrush(QColor(229,255,204)));

	painter->setPen(Qt::black);
	
	painter->drawRect(p1.x() + 10, p1.y() + 10, toolbox.size() * 7, 20);
	painter->drawText(int(p1.x() + 14), int(p1.y() + 12), toolbox.size() * 10, 20, Qt::AlignLeft, toolbox);

	painter->restore();

	Shape* forme = shapeManager->getSelectedShape();

	if (forme != nullptr) {
		
		Dimension dim = forme->getDimension();
		QPointF p2 = forme->pos;

		painter->save();

		//painter->setBrush(QBrush(QColor(229, 255, 204)));
		QPen pen(Qt::black, 2, Qt::DashLine);
		painter->setPen(pen);

		painter->drawRect(p2.x() - (dim.width / 2) - 10, p2.y() - (dim.height / 2) - 10, dim.width + 20, dim.height + 20);

		painter->restore();
	}
}

void PaintView::updateModel()
{
	// Clear
	clear();

	// Get models
	QVector<Shape*> shapes = shapeManager->getShapes();

	for (Shape* shape : shapes)
	{
		QGraphicsItem* item = shape->getGraphicsItem();
		item->setAcceptDrops(true);

		addItem(item);
	}

	update();
}

void PaintView::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton)
	{
		mousePos = mouseEvent->scenePos();
		toolbox = "mousePressEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y());

		if (QGuiApplication::keyboardModifiers().testFlag(Qt::ControlModifier)) {

			selected = this->items(mousePos);
			if (selected.size() > 1) {

				for (int i = selected.size() - 1; i >= 1; i--) {
					selected.removeAt(i);
				}
			}
			if (selected.size() == 1) {
				int id = selected[0]->data(0).toInt();
				shapeManager->addSelectShape(id);
			}
		}
		else {

			selected = this->items(mousePos);
			if (selected.size() > 1) {

				for (int i = selected.size() - 1; i >= 1; i--) {
					selected.removeAt(i);
				}
			}
			if (selected.size() == 1) {
				int id = selected[0]->data(0).toInt();
				shapeManager->selectShape(id);

			}
			else {
				shapeManager->selectShape(-1);
			}
			
		}
	}

	update();
}

void PaintView::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if ( selected.size() > 0 && (mouseEvent->buttons() & Qt::LeftButton))
	{
		QPointF mousePosNew = mouseEvent->scenePos();

		toolbox = "mouseMoveEvent (" + QString::number(mousePosNew.x()) + "," + QString::number(mousePosNew.y());
		QPointF mouseD = mousePosNew - mousePos;
		for (QGraphicsItem* item : selected)
		{
			item->moveBy(mouseD.x(), mouseD.y());
			
			QRectF rect = item->boundingRect();
			shapeManager->moveShape(item->scenePos() + rect.center());
		}

		mousePos = mousePosNew;
	}

	update();
}

void PaintView::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton)
	{
		toolbox = "mouseReleaseEvent";

		(new ControllerMoveShape(shapeManager))->control(selected);
		// Call Controller to modify the model
		selected.clear();
	}
	update();
}
