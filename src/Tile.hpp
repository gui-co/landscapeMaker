#ifndef TILE_HPP
#define TILE_HPP

#include <QVector>

class Tile
{
public:
	Tile(int northWestLatitude, int northWestLongitude,
	     int southEastLatitude, int southEastLongitude);
	void fill(QVector<uint16_t> &&elevationData);

private:
	int northWestLatitude;
	int northWestLongitude;
	int southEastLatitude;
	int southEastLongitude;
	QVector<uint16_t> data;
};

#endif /* TILE */

