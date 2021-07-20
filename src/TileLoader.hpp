#ifndef TILE_LOADER_HPP
#define TILE_LOADER_HPP

#include "Vector3d.hpp"

#include <QString>

class TileLoader
{
public:
	TileLoader(double latitude, double longitude, double elevation);

private:
	static const double WGS84_SEMI_MAJOR_AXIS;
	static const double WGS84_SEMI_MINOR_AXIS;
	static const double WGS84_EXCENTRICITY_SQUARED;
	double observerLatitude;
	double observerLongitude;
	double observerElevation;
	Vector3d ecefObserver;
	Vector3d geodeticToEcef(double latitude, double longitude,
	                        double elevation) const;
	Vector3d ecefToEnu(const Vector3d &) const;
	Vector3d geodeticToEnu(double latitude, double longitude,
	                       double elevation) const;
	void loadGeoTiff(const QString &filePath) const;
};

#endif /* TILE_LOADER */

