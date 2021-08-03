#include "Tile.hpp"

Tile::Tile(double cornerLatitude, double cornerLongitude)
	: cornerLatitude(cornerLatitude), cornerLongitude(cornerLongitude)
{
	/* Nothing to do */
}

void Tile::fill(QVector<Vector3d> &&elevationData)
{
	data = elevationData;
}

