#include "Vector3d.hpp"

Vector3d::Vector3d(double x, double y, double z)
	: x(x), y(y), z(z)
{
	/* Nothing to do */
}

double Vector3d::getX(void) const
{
	return x;
}

double Vector3d::getY(void) const
{
	return y;
}

double Vector3d::getZ(void) const
{
	return z;
}

