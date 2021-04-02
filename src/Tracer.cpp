#include "Tracer.hpp"

#include <cmath>

const double Tracer::WGS84_SEMI_MAJOR_AXIS = 6378137.0;
const double Tracer::WGS84_SEMI_MINOR_AXIS = 6356752.3142;
const double Tracer::WGS84_EXCENTRICITY_SQUARED = 0.00669437999014;

Tracer::Tracer(double observerLatitude, double observerLongitude,
               double observerElevation)
	: tile(nullptr)
{
	double n = WGS84_SEMI_MAJOR_AXIS / (sqrt(1 - WGS84_EXCENTRICITY_SQUARED
	           * pow(sin(observerLatitude), 2)));
	observerX = (n + observerElevation) * cos(observerLatitude)
	            * cos(observerLongitude);
	observerY = (n + observerElevation) * cos(observerLatitude)
	            * sin(observerLongitude);
	observerZ = (pow(WGS84_SEMI_MINOR_AXIS, 2) / pow(WGS84_SEMI_MAJOR_AXIS, 2)
	            * n + observerElevation) * sin(observerLatitude);

	int tileCornerLat = static_cast<int>(observerLatitude);
	tileCornerLat = tileCornerLat - tileCornerLat % 5;
	int tileCornerLon = static_cast<int>(observerLongitude);
	tileCornerLon = tileCornerLon - tileCornerLon % 5;
	tile = new Tile(tileCornerLat, tileCornerLon,
	                observerX, observerY, observerZ);
}

Tracer::~Tracer(void)
{
	delete tile;
}

