#include "Tile.hpp"

Tile::Tile(int northWestLatitude, int northWestLongitude,
           int southEastLatitude, int southEastLongitude)
	: northWestLatitude(northWestLatitude),
	  northWestLongitude(northWestLongitude),
	  southEastLatitude(southEastLatitude),
	  southEastLongitude(southEastLongitude)
{
	/* Nothing to do */
}

void Tile::fill(QVector<uint16_t> &&elevationData)
{
	data = elevationData;
}

