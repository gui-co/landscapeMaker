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
}

