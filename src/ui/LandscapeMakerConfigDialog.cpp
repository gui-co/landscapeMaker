#include "LandscapeMakerConfigDialog.hpp"

LandscapeMakerConfigDialog::LandscapeMakerConfigDialog(void)
	: StelDialog("LandscapeMaker")
{
	ui = new Ui_LandscapeMakerConfigDialog();
}

LandscapeMakerConfigDialog::~LandscapeMakerConfigDialog(void)
{
	delete ui;
}

void LandscapeMakerConfigDialog::retranslate(void)
{
	/* Nothing to do */
}

void LandscapeMakerConfigDialog::createDialogContent(void)
{
	ui->setupUi(dialog);
	connect(ui->closeStelWindow, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->changeLandscape, SIGNAL(clicked()),
	        this, SIGNAL(changeLandscape()));
}

double LandscapeMakerConfigDialog::getLatitude(void)
{
	return ui->latitudeField->valueDegrees();
}

double LandscapeMakerConfigDialog::getLongitude(void)
{
	return ui->longitudeField->valueDegrees();
}

double LandscapeMakerConfigDialog::getElevation(void)
{
	return ui->elevationField->value();
}

QString LandscapeMakerConfigDialog::getSelectedLandscape(void) const
{
	return "";
}

