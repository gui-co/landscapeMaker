#ifndef TILE_HPP
#define TILE_HPP

class Tile
{
public:
	Tile(double cornerLat, double cornerLon,
	     double observerX, double observerY, double observerZ);

private:
	double cornerLatitude;
	double cornerLongitude;
	double observerX;
	double observerY;
	double observerZ;
};

#endif /* TILE */

