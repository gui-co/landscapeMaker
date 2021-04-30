#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include "Vector3d.hpp"

#include <QVector>

class BoundingBox
{
public:
	BoundingBox(void);
	BoundingBox(Vector3d vMin, Vector3d vMax);
	BoundingBox(const QVector<Vector3d> &points);

private:
	Vector3d vMin;
	Vector3d vMax;
};

#endif /* BOUNDING_BOX */

