#include "Tracer.hpp"

#include <cmath>

const double Tracer::WGS84_SEMI_MAJOR_AXIS = 6378137.0;
const double Tracer::WGS84_SEMI_MINOR_AXIS = 6356752.3142;
const double Tracer::WGS84_EXCENTRICITY_SQUARED = 0.00669437999014;

Tracer::Tracer(double observerLatitude, double observerLongitude,
               double observerElevation)
	: latitude(observerLatitude), longitude(observerLongitude),
	  elevation(observerElevation), tile(nullptr)
{
	ecefObserver = geodeticToEcef(observerLatitude, observerLongitude,
	                              observerElevation);

	int tileCornerLat = static_cast<int>(latitude);
	tileCornerLat = tileCornerLat - tileCornerLat % 5;
	int tileCornerLon = static_cast<int>(longitude);
	tileCornerLon = tileCornerLon - tileCornerLon % 5;
	tile = new Tile(tileCornerLat, tileCornerLon, *this);
}

Tracer::~Tracer(void)
{
	delete tile;
}

Vector3d Tracer::geodeticToEcef(double latitude, double longitude,
                                double elevation) const
{
	double n = WGS84_SEMI_MAJOR_AXIS
	           / sqrt(1 - WGS84_EXCENTRICITY_SQUARED * pow(sin(latitude), 2));
	double x = (n + elevation) * cos(latitude) * cos(longitude);
	double y = (n + elevation) * cos(latitude) * sin(longitude);
	double z = ((pow(WGS84_SEMI_MINOR_AXIS, 2) / pow(WGS84_SEMI_MAJOR_AXIS, 2))
	           * n + elevation) * sin(latitude);

	return Vector3d(x, y, z);
}

Vector3d Tracer::ecefToEnu(const Vector3d &ecef) const
{
	Vector3d diff = ecef - ecefObserver;
	double x = -sin(longitude) * diff.getX() + cos(longitude) * diff.getY();
	double y = -sin(latitude) * cos(longitude) * diff.getX()
	           - sin(latitude) * sin(longitude) * diff.getY()
	           + cos(latitude) * diff.getZ();
	double z = cos(latitude) * cos(longitude) * diff.getX()
	           + cos(latitude) * sin(longitude) * diff.getY()
	           + sin(longitude) * diff.getZ();

	return Vector3d(x, y, z);
}

Vector3d Tracer::geodeticToEnu(double latitude, double longitude,
                               double elevation) const
{
	return ecefToEnu(geodeticToEcef(latitude, longitude, elevation));
}

