#ifndef LANDSCAPE_MAKER_CONFIG_DIALOG_HPP
#define LANDSCAPE_MAKER_CONFIG_DIALOG_HPP

#include "ui_LandscapeMakerConfigDialog.h"

#include "StelDialog.hpp"

#include <QString>

class LandscapeMakerConfigDialog: public StelDialog
{
	Q_OBJECT

signals:
	void changeLandscape(void);

public:
	LandscapeMakerConfigDialog(void);
	~LandscapeMakerConfigDialog(void);
	virtual void retranslate(void);
	virtual void createDialogContent(void);
	double getLatitude(void);
	double getLongitude(void);
	double getElevation(void);
	QString getSelectedLandscape(void) const;

private:
	Ui_LandscapeMakerConfigDialog *ui;
};

#endif /* LANDSCAPE_MAKER_CONFIG_DIALOG */

