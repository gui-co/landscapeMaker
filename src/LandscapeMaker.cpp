#include "LandscapeMaker.hpp"

LandscapeMaker::LandscapeMaker(void)
{
	setObjectName("LandscapeMaker");
	configDialog = new LandscapeMakerConfigDialog();
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

