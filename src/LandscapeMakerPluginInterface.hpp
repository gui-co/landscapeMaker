#ifndef LANDSCAPE_MAKER_PLUGIN_INTERFACE_HPP
#define LANDSCAPE_MAKER_PLUGIN_INTERFACE_HPP

#include "StelModule.hpp"
#include "StelPluginInterface.hpp"

#include <QObject>
#include <QObjectList>

class LandscapeMakerPluginInterface: public QObject, public StelPluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID StelPluginInterface_iid)
	Q_INTERFACES(StelPluginInterface)

public:
	virtual StelModule *getStelModule(void) const;
	virtual StelPluginInfo getPluginInfo(void) const;
	virtual QObjectList getExtensionList(void) const;
};

#endif /* LANDSCAPE_MAKER_PLUGIN_INTERFACE */

