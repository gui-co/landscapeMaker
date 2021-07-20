#include "Tracer.hpp"

#include <cmath>

const double Tracer::WGS84_SEMI_MAJOR_AXIS = 6378137.0;
const double Tracer::WGS84_SEMI_MINOR_AXIS = 6356752.3142;
const double Tracer::WGS84_EXCENTRICITY_SQUARED = 0.00669437999014;

Tracer::Tracer(double observerLatitude, double observerLongitude,
               double observerElevation)
	: latitude(observerLatitude), longitude(observerLongitude),
	  elevation(observerElevation)
{
	ecefObserver = geodeticToEcef(observerLatitude, observerLongitude,
	                              observerElevation);
}

Vector3d Tracer::geodeticToEcef(double latitude, double longitude,
                                double elevation) const
{
	double latRad = latitude * M_PI / 180.0;
	double lonRad = longitude * M_PI / 180.0;
	double n = WGS84_SEMI_MAJOR_AXIS
	           / sqrt(1 - WGS84_EXCENTRICITY_SQUARED * pow(sin(latRad), 2));
	double x = (n + elevation) * cos(latRad) * cos(lonRad);
	double y = (n + elevation) * cos(latRad) * sin(lonRad);
	double z = ((pow(WGS84_SEMI_MINOR_AXIS, 2) / pow(WGS84_SEMI_MAJOR_AXIS, 2))
	           * n + elevation) * sin(latRad);

	return Vector3d(x, y, z);
}

Vector3d Tracer::ecefToEnu(const Vector3d &ecef) const
{
	double latRad = latitude * M_PI / 180.0;
	double lonRad = longitude * M_PI / 180.0;
	Vector3d diff = ecef - ecefObserver;
	double x = -sin(latRad) * diff.getX() + cos(lonRad) * diff.getY();
	double y = -sin(latRad) * cos(lonRad) * diff.getX()
	           - sin(latRad) * sin(lonRad) * diff.getY()
	           + cos(latRad) * diff.getZ();
	double z = cos(latRad) * cos(lonRad) * diff.getX()
	           + cos(latRad) * sin(lonRad) * diff.getY()
	           + sin(latRad) * diff.getZ();

	return Vector3d(x, y, z);
}

Vector3d Tracer::geodeticToEnu(double latitude, double longitude,
                               double elevation) const
{
	return ecefToEnu(geodeticToEcef(latitude, longitude, elevation));
}

