#ifndef LANDSCAPE_MAKER_CONFIG_DIALOG_HPP
#define LANDSCAPE_MAKER_CONFIG_DIALOG_HPP

#include "StelDialog.hpp"

class LandscapeMakerConfigDialog: public StelDialog
{
	Q_OBJECT

public:
	LandscapeMakerConfigDialog(void);
	~LandscapeMakerConfigDialog(void);
	virtual void retranslate(void);
	virtual void createDialogContent(void);
};

#endif /* LANDSCAPE_MAKER_CONFIG_DIALOG */

