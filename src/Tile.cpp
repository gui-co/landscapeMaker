#include "Tile.hpp"

Tile::Tile(double cornerLatitude, double cornerLongitude,
           double observerX, double observerY, double observerZ)
	: cornerLatitude(cornerLatitude), cornerLongitude(cornerLongitude),
	  observerX(observerX), observerY(observerY), observerZ(observerZ)
{
	// filename for srtm.csi.cgiar.org data
	int nLon = cornerLongitude / 5 + 37;
	int nLat = -cornerLatitude / 5 + 12;
	filename = QString("srtm_%1_%2.tif").arg(nLon).arg(nLat);
}

