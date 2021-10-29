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
	latitudeResolution = (northWestLatitude - southEastLatitude)
	                     / nbLatitudePoints;
	longitudeResolution = (southEastLongitude - northWestLongitude)
	                      / nbLongitudePoints;
}

size_t Tile::getNbLongitudePoints(void)
{
	return nbLongitudePoints;
}

size_t Tile::getNbLatitudePoints(void)
{
	return nbLatitudePoints;
}

double Tile::getLatitude(size_t latIndex)
{
	return northWestLatitude - latIndex * latitudeResolution;
}

double Tile::getLongitude(size_t lonIndex)
{
	return northWestLongitude + lonIndex * longitudeResolution;
}

uint16_t Tile::getElevation(size_t latIndex, size_t lonIndex)
{
	return data[lonIndex + latIndex * nbLongitudePoints];
}

