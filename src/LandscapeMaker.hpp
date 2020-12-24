#ifndef LANDSCAPE_MAKER_HPP
#define LANDSCAPE_MAKER_HPP

#include "StelCore.hpp"
#include "StelModule.hpp"

#include <QString>

class LandscapeMaker: public StelModule
{
	Q_OBJECT

public:
	virtual void init(void);
	virtual void deinit(void);
	virtual void update(double deltaTime);
};

#endif /* LANDSCAPE_MAKER */

