#include "frmosgqt.h"

frmOsgQt::frmOsgQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

osgQOpenGLWidget* frmOsgQt::getOsgQOpenGLWidget()
{
	return ui.openGLWidget;
}