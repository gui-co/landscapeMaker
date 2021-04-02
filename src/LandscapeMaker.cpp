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
	landscape = new Landscape(2048, 1024);
}

LandscapeMaker::~LandscapeMaker(void)
{
	delete configDialog;
	delete landscape;
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
	landscape->save("artificialLandscape", landscapeDir);
	lm->setProperty("currentLandscapeName", "artificialLandscape");
}

