#ifndef TILE_HPP
#define TILE_HPP

#include "Vector3d.hpp"
#include "BoundingBox.hpp"

#include <QVector>

class Tracer;

class Tile
{
public:
	Tile(double cornerLat, double cornerLon, const Tracer &tracer);

private:
	double cornerLatitude;
	double cornerLongitude;
	const Tracer &tracer;
	QVector<Vector3d> data;
	BoundingBox largeBoundingBox;
	Tile *north;
	Tile *south;
	Tile *east;
	Tile *west;
};

#endif /* TILE */

