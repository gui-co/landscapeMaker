#include "Tile.hpp"

Tile::Tile(double cornerLatitude, double cornerLongitude, const Tracer &tracer)
	: cornerLatitude(cornerLatitude), cornerLongitude(cornerLongitude),
	  tracer(tracer)
{
	/* Nothing to do */
}

