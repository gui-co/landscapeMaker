#ifndef TILE_LOADER_HPP
#define TILE_LOADER_HPP

class TileLoader
{
public:
	TileLoader(double latitude, double longitude, double elevation);

private:
	double observerLatitude;
	double observerLongitude;
	double observerElevation;
};

#endif /* TILE_LOADER */

