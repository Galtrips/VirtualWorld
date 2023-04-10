/********************************************************************************
** Form generated from reading UI file 'virtualworld.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALWORLD_H
#define UI_VIRTUALWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VirtualWorldClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QRadioButton *radioButton_Circle;
    QRadioButton *radioButton_Square;
    QRadioButton *radioButton_Rectangle;
    QPushButton *Object_GroupButton;
    QPushButton *Object_AddButton;
    QPushButton *Object_RemoveButton;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VirtualWorldClass)
    {
        if (VirtualWorldClass->objectName().isEmpty())
            VirtualWorldClass->setObjectName(QString::fromUtf8("VirtualWorldClass"));
        VirtualWorldClass->resize(875, 575);
        centralWidget = new QWidget(VirtualWorldClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

        horizontalLayout_2->addWidget(graphicsView);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(200, 0));
        widget_2->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 150));
        radioButton_Circle = new QRadioButton(groupBox);
        radioButton_Circle->setObjectName(QString::fromUtf8("radioButton_Circle"));
        radioButton_Circle->setGeometry(QRect(20, 20, 89, 20));
        radioButton_Circle->setChecked(true);
        radioButton_Square = new QRadioButton(groupBox);
        radioButton_Square->setObjectName(QString::fromUtf8("radioButton_Square"));
        radioButton_Square->setGeometry(QRect(20, 40, 89, 20));
        radioButton_Rectangle = new QRadioButton(groupBox);
        radioButton_Rectangle->setObjectName(QString::fromUtf8("radioButton_Rectangle"));
        radioButton_Rectangle->setGeometry(QRect(20, 60, 89, 20));
        Object_GroupButton = new QPushButton(groupBox);
        Object_GroupButton->setObjectName(QString::fromUtf8("Object_GroupButton"));
        Object_GroupButton->setGeometry(QRect(10, 120, 75, 24));
        Object_AddButton = new QPushButton(groupBox);
        Object_AddButton->setObjectName(QString::fromUtf8("Object_AddButton"));
        Object_AddButton->setGeometry(QRect(10, 90, 75, 24));
        Object_RemoveButton = new QPushButton(groupBox);
        Object_RemoveButton->setObjectName(QString::fromUtf8("Object_RemoveButton"));
        Object_RemoveButton->setGeometry(QRect(90, 90, 75, 24));

        verticalLayout->addWidget(groupBox);

        treeWidget = new QTreeWidget(widget_2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        horizontalLayout->addWidget(widget_2);

        VirtualWorldClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VirtualWorldClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 22));
        VirtualWorldClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VirtualWorldClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VirtualWorldClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VirtualWorldClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VirtualWorldClass->setStatusBar(statusBar);

        retranslateUi(VirtualWorldClass);

        QMetaObject::connectSlotsByName(VirtualWorldClass);
    } // setupUi

    void retranslateUi(QMainWindow *VirtualWorldClass)
    {
        VirtualWorldClass->setWindowTitle(QCoreApplication::translate("VirtualWorldClass", "VirtualWorld", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VirtualWorldClass", "Objects", nullptr));
        radioButton_Circle->setText(QCoreApplication::translate("VirtualWorldClass", "Circle", nullptr));
        radioButton_Square->setText(QCoreApplication::translate("VirtualWorldClass", "Square", nullptr));
        radioButton_Rectangle->setText(QCoreApplication::translate("VirtualWorldClass", "Rectangle", nullptr));
        Object_GroupButton->setText(QCoreApplication::translate("VirtualWorldClass", "Group", nullptr));
        Object_AddButton->setText(QCoreApplication::translate("VirtualWorldClass", "Add", nullptr));
        Object_RemoveButton->setText(QCoreApplication::translate("VirtualWorldClass", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VirtualWorldClass: public Ui_VirtualWorldClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALWORLD_H
