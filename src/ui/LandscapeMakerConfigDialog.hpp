#ifndef LANDSCAPE_MAKER_CONFIG_DIALOG_HPP
#define LANDSCAPE_MAKER_CONFIG_DIALOG_HPP

#include "ui_LandscapeMakerConfigDialog.h"

#include "StelDialog.hpp"

class LandscapeMakerConfigDialog: public StelDialog
{
	Q_OBJECT

public:
	LandscapeMakerConfigDialog(void);
	~LandscapeMakerConfigDialog(void);
	virtual void retranslate(void);
	virtual void createDialogContent(void);

private:
	Ui_LandscapeMakerConfigDialog *ui;
};

#endif /* LANDSCAPE_MAKER_CONFIG_DIALOG */

