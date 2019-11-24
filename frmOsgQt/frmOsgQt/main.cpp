#include "frmosgqt.h"
#include <QtWidgets/QApplication>

#include "libs.h"

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/SphericalManipulator>
#include <osgGA/Device>

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>

#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osg/Shape>

#include <osgQOpenGL/osgQOpenGLWidget>

int main(int argc, char** argv)
{
	QSurfaceFormat format = QSurfaceFormat::defaultFormat();

#ifdef OSG_GL3_AVAILABLE
	format.setVersion(3, 2);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setOption(QSurfaceFormat::DebugContext);
#else
	format.setVersion(2, 0);
	format.setProfile(QSurfaceFormat::CompatibilityProfile);
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setOption(QSurfaceFormat::DebugContext);
#endif
	format.setDepthBufferSize(24);
	//format.setAlphaBufferSize(8);
	format.setSamples(8);
	format.setStencilBufferSize(8);
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	QSurfaceFormat::setDefaultFormat(format);

	QApplication app(argc, argv);

	osg::ArgumentParser arguments(&argc, argv);

	// use an ArgumentParser object to manage the program arguments.
	frmOsgQt *w = new frmOsgQt;

	osgQOpenGLWidget *widget = w->getOsgQOpenGLWidget();

	QObject::connect(widget, &osgQOpenGLWidget::initialized, [&arguments,
		widget]
	{
		unsigned int helpType = 0;

		// set up the camera manipulators.
		{
			osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

			keyswitchManipulator->addMatrixManipulator('1', "Trackball", new osgGA::TrackballManipulator());
			keyswitchManipulator->addMatrixManipulator('2', "Flight", new osgGA::FlightManipulator());
			keyswitchManipulator->addMatrixManipulator('3', "Drive", new osgGA::DriveManipulator());
			keyswitchManipulator->addMatrixManipulator('4', "Terrain", new osgGA::TerrainManipulator());
			keyswitchManipulator->addMatrixManipulator('5', "Orbit", new osgGA::OrbitManipulator());
			keyswitchManipulator->addMatrixManipulator('6', "FirstPerson", new osgGA::FirstPersonManipulator());
			keyswitchManipulator->addMatrixManipulator('7', "Spherical", new osgGA::SphericalManipulator());

			widget->getOsgViewer()->setCameraManipulator(keyswitchManipulator.get());
		}

		// add the state manipulator
		widget->getOsgViewer()->addEventHandler(new osgGA::StateSetManipulator(widget->getOsgViewer()->getCamera()->getOrCreateStateSet()));

		// add the thread model handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::ThreadingHandler);

		// add the window size toggle handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::WindowSizeHandler);

		// add the stats handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::StatsHandler);

		// add the help handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::HelpHandler());

		// add the record camera path handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::RecordCameraPathHandler);

		// add the LOD Scale handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::LODScaleHandler);

		// add the screen capture handler
		widget->getOsgViewer()->addEventHandler(new osgViewer::ScreenCaptureHandler);

		// load the data
		//osg::ref_ptr<osg::Node> loadedModel = osgDB::readRefNodeFiles(arguments);
		osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile("cow.osg");

		// optimize the scene graph, remove redundant nodes and state etc.
		//osgUtil::Optimizer optimizer;
		//optimizer.optimize(createShape());

		widget->getOsgViewer()->setSceneData(loadedModel);
		//widget->getOsgViewer()->setSceneData(createShape());
		//widget.getOsgViewer()->realize();

		return 0;
	});

	w->show();
	return app.exec();
}
