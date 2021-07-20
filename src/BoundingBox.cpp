#include "BoundingBox.hpp"

#include <limits>

BoundingBox::BoundingBox(void)
{
	/* Nothing to do */
}

BoundingBox::BoundingBox(Vector3d vMin, Vector3d vMax)
	: vMin(vMin), vMax(vMax)
{
	/* Nothing to do */
}

BoundingBox::BoundingBox(const QVector<Vector3d> &points)
{
	double xMin = std::numeric_limits<double>::infinity();
	double yMin = std::numeric_limits<double>::infinity();
	double zMin = std::numeric_limits<double>::infinity();
	double xMax = -std::numeric_limits<double>::infinity();
	double yMax = -std::numeric_limits<double>::infinity();
	double zMax = -std::numeric_limits<double>::infinity();

	for (auto point: points)
	{
		double x = point.getX();
		double y = point.getY();
		double z = point.getZ();
		if (x < xMin)
			xMin = x;
		if (x > xMax)
			xMax = x;
		if (y < yMin)
			yMin = y;
		if (y > yMax)
			yMax = y;
		if (z < zMin)
			zMin = z;
		if (z > zMax)
			zMax = z;
	}
	vMin = Vector3d(xMin, yMin, zMin);
	vMax = Vector3d(xMax, yMax, zMax);
}

