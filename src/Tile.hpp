#ifndef TILE_HPP
#define TILE_HPP

#include "Vector3d.hpp"

#include <QString>
#include <QVector>

class Tracer;

class Tile
{
public:
	Tile(double cornerLat, double cornerLon, const Tracer &tracer);

private:
	double cornerLatitude;
	double cornerLongitude;
	const Tracer &tracer;
	QString filename;
	QVector<Vector3d> data;
	void loadFile(void);
};

#endif /* TILE */

