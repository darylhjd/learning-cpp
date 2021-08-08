#ifndef VECTOR_3D
#define VECTOR_3D

#include "Point3d.h"

class Vector3d {
    double m_x{};
    double m_y{};
    double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{x}, m_y{y}, m_z{z}
	{}

    void print() const;
    friend void Point3d::moveByVector(const Vector3d& v);
};

#endif