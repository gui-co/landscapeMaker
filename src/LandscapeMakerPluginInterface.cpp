#include "LandscapeMakerPluginInterface.hpp"
#include "LandscapeMaker.hpp"

StelModule *LandscapeMakerPluginInterface::getStelModule(void) const
{
	return new LandscapeMaker();
}

StelPluginInfo LandscapeMakerPluginInterface::getPluginInfo(void) const
{
	StelPluginInfo info;
	info.id = "LandscapeMaker";
	info.displayedName = "Landscape Maker";
	info.authors = "Guillaume Communie";
	info.contact = "gui-co@posteo.net";
	info.license = "GPLv2+";
	return info;
}

QObjectList LandscapeMakerPluginInterface::getExtensionList(void) const
{
	return QObjectList();
}

