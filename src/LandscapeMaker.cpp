#include "LandscapeMaker.hpp"

#include "StelApp.hpp"
#include "StelFileMgr.hpp"

LandscapeMaker::LandscapeMaker(void)
{
	setObjectName("LandscapeMaker");
	configDialog = new LandscapeMakerConfigDialog();
	QDir userDir = QDir(StelFileMgr::getUserDir());
	userDir.mkdir("landscapes");
	landscapeDir = QDir(userDir.filePath("landscapes"));
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
	double latitude = configDialog->getLatitude();
	double longitude = configDialog->getLongitude();
	double elevation = configDialog->getElevation();
	tracer = new Tracer(latitude, longitude, elevation);
}

