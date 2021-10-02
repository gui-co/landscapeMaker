#ifndef TILE_HPP
#define TILE_HPP

#include "Vector3d.hpp"
#include "BoundingBox.hpp"

#include <QVector>

class Tile
{
public:
	Tile(int southWestLat, int southWestLon, int northEastLat,
	     int northEastLon);
	void fill(QVector<Vector3d> &&elevationData);

private:
	int southWestLat;
	int southWestLon;
	int northEastLat;
	int northEastLon;
	QVector<Vector3d> data;
	BoundingBox largeBoundingBox;
	Tile *north;
	Tile *south;
	Tile *east;
	Tile *west;
};

#endif /* TILE */

