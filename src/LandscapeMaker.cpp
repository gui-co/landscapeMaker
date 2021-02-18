#include "LandscapeMaker.hpp"

#include "StelApp.hpp"
#include "StelFileMgr.hpp"

#include <QImage>
#include <QDir>
#include <QColor>
#include <QFile>
#include <QTextStream>

LandscapeMaker::LandscapeMaker(void)
{
	setObjectName("LandscapeMaker");
	configDialog = new LandscapeMakerConfigDialog();
	QDir userDir = QDir(StelFileMgr::getUserDir());
	userDir.mkdir("landscapes");
	landscapeDir = new QDir(userDir.filePath("landscapes"));
	connect(configDialog, SIGNAL(changeLandscape()),
	        this, SLOT(onChangeLandscape()));
}

LandscapeMaker::~LandscapeMaker(void)
{
	delete configDialog;
}

void LandscapeMaker::init(void)
{
	/* Nothing to do */
}

void LandscapeMaker::deinit(void)
{
	/* Nothing to do */
}

void LandscapeMaker::update(double deltaTime)
{
	/* Nothing to do */
}

bool LandscapeMaker::configureGui(bool show)
{
	if (show)
		configDialog->setVisible(true);
	return true;
}

void LandscapeMaker::onChangeLandscape(void)
{
	QString id = configDialog->getSelectedLandscape();
	StelApp &app = StelApp::getInstance();
	StelModule *lm = app.getModule("LandscapeMgr");
	saveLandscape();
	lm->setProperty("currentLandscapeName", "artificialLandscape");
}

void LandscapeMaker::saveLandscape(void)
{
	landscapeDir->mkdir("artificialLandscape");
	QDir currentLandscapeDir(landscapeDir->filePath("artificialLandscape"));
	QString imagePath = currentLandscapeDir.filePath("image.png");
	QString iniPath = currentLandscapeDir.filePath("landscape.ini");

	// image
	QImage image(2048, 1024, QImage::Format_ARGB32);
	for (int i = 0 ; i < 2048 ; i++)
	{
		int j = 0;
		while (j < 512)
		{
			image.setPixelColor(i, j, QColor(0, 0, 0, 0));
			j++;
		}
		while (j < 1024)
		{
			image.setPixelColor(i, j, QColor(255, 255, 255, 255));
			j++;
		}
	}
	image.save(imagePath);

	// conf
	QFile iniFile(iniPath);
	iniFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream iniTs(&iniFile);
	iniTs << "[landscape]"                         << "\n";
	iniTs << "name = " << "artificialLandscape"    << "\n";
	iniTs << "type = spherical"                    << "\n";
	iniTs << "maptex = image.png"                  << "\n";
	iniFile.close();
}

