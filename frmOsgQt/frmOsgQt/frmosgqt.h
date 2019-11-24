#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_frmosgqt.h"

#include <osgQOpenGL/osgQOpenGLWidget>

class frmOsgQt : public QMainWindow
{
	Q_OBJECT

public:
	frmOsgQt(QWidget *parent = Q_NULLPTR);
	osgQOpenGLWidget* getOsgQOpenGLWidget();
private:
	Ui::frmOsgQtClass ui;
};
