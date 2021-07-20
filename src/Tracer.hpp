#ifndef TRACER_HPP
#define TRACER_HPP

#include "Tile.hpp"
#include "Vector3d.hpp"

#include <list>

class Tracer
{
public:
	Tracer(double, double, double);
	Vector3d geodeticToEcef(double latitude, double longitude,
	                        double elevation) const;
	Vector3d ecefToEnu(const Vector3d &ecef) const;
	Vector3d geodeticToEnu(double latitude, double longitude, double elevation) const;
	void traceLandscape(void);
	static const double WGS84_SEMI_MAJOR_AXIS;
	static const double WGS84_SEMI_MINOR_AXIS;
	static const double WGS84_EXCENTRICITY_SQUARED;

private:
	double latitude;
	double longitude;
	double elevation;
	Vector3d ecefObserver;
	std::list<Tile> tiles;
};

#endif /* TRACER */

