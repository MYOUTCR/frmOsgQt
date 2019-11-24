/********************************************************************************
** Form generated from reading UI file 'frmosgqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMOSGQT_H
#define UI_FRMOSGQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <osgQOpenGL/osgQOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_frmOsgQtClass
{
public:
    QWidget *centralWidget;
    osgQOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *frmOsgQtClass)
    {
        if (frmOsgQtClass->objectName().isEmpty())
            frmOsgQtClass->setObjectName(QStringLiteral("frmOsgQtClass"));
        frmOsgQtClass->resize(710, 515);
        centralWidget = new QWidget(frmOsgQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new osgQOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(29, 19, 651, 441));
        frmOsgQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(frmOsgQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 710, 23));
        frmOsgQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(frmOsgQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        frmOsgQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(frmOsgQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        frmOsgQtClass->setStatusBar(statusBar);

        retranslateUi(frmOsgQtClass);

        QMetaObject::connectSlotsByName(frmOsgQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *frmOsgQtClass)
    {
        frmOsgQtClass->setWindowTitle(QApplication::translate("frmOsgQtClass", "frmOsgQt", 0));
    } // retranslateUi

};

namespace Ui {
    class frmOsgQtClass: public Ui_frmOsgQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMOSGQT_H
