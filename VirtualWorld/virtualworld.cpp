#include "virtualworld.h"
#include "controller.h"
#include <QDebug>
#include <QShortcut>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm)
    : QMainWindow(parent), shapeManager(sm)
{
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttons
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
    //connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_I), this), &QShortcut::activated, []() {qDebug() << "Here we are!"; });
}

VirtualWorld::~VirtualWorld()
{}

void VirtualWorld::addShape()
{
    QVector<QRadioButton*> button;

    button.append(ui.radioButton_Circle);
    button.append(ui.radioButton_Square);
    button.append(ui.radioButton_Rectangle);

    ControllerAdd(shapeManager).control(button);
}
