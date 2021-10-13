#ifndef TILE_LOADER_HPP
#define TILE_LOADER_HPP

#include "Vector3d.hpp"

#include <QString>
#include <QStringList>
#include <QVector>

class TileLoader
{
public:
	TileLoader(double latitude, double longitude, double elevation);
	QStringList getFilenames(void);

private:
	static const double WGS84_SEMI_MAJOR_AXIS;
	static const double WGS84_SEMI_MINOR_AXIS;
	static const double WGS84_EXCENTRICITY_SQUARED;
	static const int TILE_SIZE;
	static const int TILE_RESOLUTION;
	static const QString SRTM_BASE_NAME;
	double observerLatitude;
	double observerLongitude;
	double observerElevation;
	QStringList filenames;
	Vector3d ecefObserver;
	Vector3d geodeticToEcef(double latitude, double longitude,
	                        double elevation) const;
	Vector3d ecefToEnu(const Vector3d &) const;
	Vector3d geodeticToEnu(double latitude, double longitude,
	                       double elevation) const;
	QVector<Vector3d> loadGeoTiff(const QString &filePath) const;
};

#endif /* TILE_LOADER */

