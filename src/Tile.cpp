#include "Tile.hpp"

Tile::Tile(int southWestLat, int southWestLon,
           int northEastLat, int northEastLon)
	: southWestLat(southWestLat), southWestLon(southWestLon),
	  northEastLat(northEastLat), northEastLon(northEastLon)
{
	/* Nothing to do */
}

void Tile::fill(QVector<Vector3d> &&elevationData)
{
	data = elevationData;
}

