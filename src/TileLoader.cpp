#include "TileLoader.hpp"

#include <QByteArray>

#include <tiffio.h>

#include <cmath>

const double TileLoader::WGS84_SEMI_MAJOR_AXIS = 6378137.0;
const double TileLoader::WGS84_SEMI_MINOR_AXIS = 6356752.3142;
const double TileLoader::WGS84_EXCENTRICITY_SQUARED = 0.00669437999014;
const int TileLoader::TILE_SIZE = 5 * 3600;
const int TileLoader::TILE_RESOLUTION = 3;
const QString TileLoader::SRTM_BASE_NAME = "srtm_%1_%2.tif";

TileLoader::TileLoader(double observerLatitude, double observerLongitude,
                       double observerElevation)
{
	QStringList filenames;
	int size = 5;
	int lat = (int) observerLatitude + size;
	while (lat >= (int) observerLatitude - size)
	{
		int n_lat = (60 - lat) / 5 + 1;
		int lon = (int) observerLongitude - size;
		while (lon <= (int) observerLongitude + size)
		{
			int n_lon = (180 + lon) / 5 + 1;
			filenames << SRTM_BASE_NAME.arg(n_lat, n_lon);
			lon = lon + 5;
		}
		lat = lat - 5;
	}
}

QStringList TileLoader::getFilenames(void)
{
	return filenames;
}

Vector3d TileLoader::geodeticToEcef(double latitude, double longitude,
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

Vector3d TileLoader::ecefToEnu(const Vector3d &ecef) const
{
	double latRad = observerLatitude * M_PI / 180.0;
	double lonRad = observerLongitude * M_PI / 180.0;
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

Vector3d TileLoader::geodeticToEnu(double latitude, double longitude,
                                   double elevation) const
{
	return ecefToEnu(geodeticToEcef(latitude, longitude, elevation));
}

QVector<Vector3d> TileLoader::loadGeoTiff(const QString &filePath) const
{
	double cornerLatitude = 0;
	double cornerLongitude = 0;
	QVector<Vector3d> data(6000 * 6000);
	QByteArray filePathUtf8 = filePath.toUtf8();
	TIFF* tif = TIFFOpen(filePathUtf8.constData(), "r");
	if (!tif) {
		data.resize(0);
		return data;
	}
	uint32_t w, h, l;
	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &w);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &l);

	int16_t *lineBuffer;
	lineBuffer = new int16_t[6000];
	for (int i = 0 ; i < 6000 ; i++)
	{
		TIFFReadScanline(tif, lineBuffer, i);
		for (int j = 0; j < 6000; j++)
		{
			double lat = cornerLatitude + (j / 6000) * 3 / 3600;
			double lon = cornerLongitude + (j % 6000) * 3 / 3600;
			double alt = lineBuffer[j];
			data[i * j] = geodeticToEnu(lat, lon, alt);
		}
	}
	delete lineBuffer;
	TIFFClose(tif);
	return data;
}

