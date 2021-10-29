#ifndef TILE_HPP
#define TILE_HPP

#include <QVector>

class Tile
{
public:
	Tile(int northWestLatitude, int northWestLongitude,
	     int southEastLatitude, int southEastLongitude);
	void fill(QVector<uint16_t> elevationData,
	          size_t width, size_t height);
	size_t getNbLongitudePoints(void);
	size_t getNbLatitudePoints(void);

private:
	int northWestLatitude;
	int northWestLongitude;
	int southEastLatitude;
	int southEastLongitude;
	size_t nbLongitudePoints;
	size_t nbLatitudePoints;
	int latitudeResolution;
	int longitudeResolution;
	QVector<uint16_t> data;
};

#endif /* TILE */

