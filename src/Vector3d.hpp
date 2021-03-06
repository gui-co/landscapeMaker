#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

class Vector3d
{
public:
	Vector3d(void);
	Vector3d(double x, double y, double z);
	Vector3d operator-(const Vector3d &rhs) const;
	double getX(void) const;
	double getY(void) const;
	double getZ(void) const;

private:
	double x;
	double y;
	double z;
};

#endif /* VECTOR_3D */

