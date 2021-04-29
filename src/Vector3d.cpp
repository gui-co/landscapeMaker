#include "Vector3d.hpp"

Vector3d::Vector3d(void)
	: x(0.0), y(0.0), z(0.0)
{
	/* Nothing to do */
}

Vector3d::Vector3d(double x, double y, double z)
	: x(x), y(y), z(z)
{
	/* Nothing to do */
}

Vector3d Vector3d::operator-(const Vector3d &rhs) const
{
	return Vector3d(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
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

