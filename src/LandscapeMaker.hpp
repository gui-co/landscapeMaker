#ifndef LANDSCAPE_MAKER_HPP
#define LANDSCAPE_MAKER_HPP

#include "LandscapeMakerConfigDialog.hpp"
#include "Landscape.hpp"

#include "StelCore.hpp"
#include "StelModule.hpp"

#include <QString>
#include <QDir>

class LandscapeMaker: public StelModule
{
	Q_OBJECT

public:
	LandscapeMaker(void);
	~LandscapeMaker(void);
	virtual void init(void);
	virtual void deinit(void);
	virtual void update(double deltaTime);
	virtual bool configureGui(bool show);

private:
	LandscapeMakerConfigDialog *configDialog;
	QDir landscapeDir;
	Landscape *landscape;

private slots:
	void onChangeLandscape(void);
};

#endif /* LANDSCAPE_MAKER */

