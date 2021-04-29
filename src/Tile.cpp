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
			data.append(tracer.geodeticToEnu(lat, lon, alt));
		}
	}
	delete lineBuffer;
	TIFFClose(tif);
}

