#ifndef TILE_HPP
#define TILE_HPP

#include <QVector>

class Tile
{
public:
	Tile(int southWestLat, int southWestLon, int northEastLat,
	     int northEastLon);
	void fill(QVector<uint16_t> &&elevationData);

private:
	int southWestLat;
	int southWestLon;
	int northEastLat;
	int northEastLon;
	QVector<uint16_t> data;
};

#endif /* TILE */

