#include "LandscapeMaker.hpp"

#include "StelApp.hpp"

LandscapeMaker::LandscapeMaker(void)
{
	setObjectName("LandscapeMaker");
	configDialog = new LandscapeMakerConfigDialog();
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
}

