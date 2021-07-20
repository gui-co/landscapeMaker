#ifndef TILE_HPP
#define TILE_HPP

#include "Vector3d.hpp"
#include "BoundingBox.hpp"

#include <QVector>

class Tile
{
public:
	Tile(double cornerLat, double cornerLon);

private:
	double cornerLatitude;
	double cornerLongitude;
	QVector<Vector3d> data;
	BoundingBox largeBoundingBox;
	Tile *north;
	Tile *south;
	Tile *east;
	Tile *west;
};

#endif /* TILE */

