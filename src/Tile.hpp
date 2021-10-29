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
	double getLatitude(size_t latIndex);
	double getLongitude(size_t lonIndex);
	uint16_t getElevation(size_t latIndex, size_t lonIndex);

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

