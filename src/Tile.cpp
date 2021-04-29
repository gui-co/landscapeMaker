#include "Tile.hpp"

#include "Tracer.hpp"

#include <QByteArray>

#include <tiffio.h>

#include <cstdint>
#include <cmath>

Tile::Tile(double cornerLatitude, double cornerLongitude, const Tracer &tracer)
	: cornerLatitude(cornerLatitude), cornerLongitude(cornerLongitude),
	  tracer(tracer)
{
	// filename for srtm.csi.cgiar.org data
	int nLon = cornerLongitude / 5 + 37;
	int nLat = -cornerLatitude / 5 + 12;
	filename = QString("srtm_%1_%2.tif").arg(nLon).arg(nLat);
}

void Tile::loadFile(void)
{
	QByteArray filenameUtf8 = filename.toUtf8();
	TIFF* tif = TIFFOpen(filenameUtf8.constData(), "r");
	if (!tif)
		return;
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
			double n = Tracer::WGS84_SEMI_MAJOR_AXIS
			           / sqrt(1 - Tracer::WGS84_EXCENTRICITY_SQUARED
			           * pow(sin(lat), 2));
			data.append(
			    Vector3d((n + alt) * cos(lat) * cos(lon),
			             (n + alt) * cos(lat) * sin(lon),
			             ((pow(Tracer::WGS84_SEMI_MINOR_AXIS, 2)
			              / pow(Tracer::WGS84_SEMI_MAJOR_AXIS, 2)) * n + h)
			              * sin(lat)));
		}
	}
	delete lineBuffer;
	TIFFClose(tif);
}

