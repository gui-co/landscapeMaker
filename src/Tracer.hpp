#ifndef TRACER_HPP
#define TRACER_HPP

#include "Tile.hpp"
#include "TileLoader.hpp"

#include <list>

class Tracer
{
public:
	Tracer(double observerLatitude, double observerLongitude,
	       double observerElevation);
	void traceLandscape(void);

private:
	double latitude;
	double longitude;
	double elevation;
	TileLoader loader;
	std::list<Tile> tiles;
};

#endif /* TRACER */

