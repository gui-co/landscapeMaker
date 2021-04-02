#ifndef TRACER_HPP
#define TRACER_HPP

#include "Tile.hpp"

class Tracer
{
public:
	Tracer(double, double, double);
	~Tracer(void);
	void traceLandscape(void);
	static const double WGS84_SEMI_MAJOR_AXIS;
	static const double WGS84_SEMI_MINOR_AXIS;
	static const double WGS84_EXCENTRICITY_SQUARED;

private:
	double observerX;
	double observerY;
	double observerZ;
};

#endif /* TRACER */

