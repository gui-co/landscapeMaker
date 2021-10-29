#include "Tile.hpp"

Tile::Tile(int northWestLatitude, int northWestLongitude,
           int southEastLatitude, int southEastLongitude)
	: northWestLatitude(northWestLatitude),
	  northWestLongitude(northWestLongitude),
	  southEastLatitude(southEastLatitude),
	  southEastLongitude(southEastLongitude),
	  nbLatitudePoints(0), nbLongitudePoints(0)
{
	/* Nothing to do */
}

void Tile::fill(QVector<uint16_t> elevationData,
                size_t width, size_t height)
{
	data = std::move(elevationData);
	nbLongitudePoints = width;
	nbLatitudePoints = height;
}

size_t Tile::getNbLongitudePoints(void)
{
	return nbLongitudePoints;
}

size_t Tile::getNbLatitudePoints(void)
{
	return nbLatitudePoints;
}

