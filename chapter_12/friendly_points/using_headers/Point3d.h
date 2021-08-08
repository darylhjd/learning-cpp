#ifndef POINT_3D
#define POINT_3D

class Vector3d;

class Point3d {
    double m_x{};
    double m_y{};
    double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0);
 
	void print() const;
    void moveByVector(const Vector3d& v);
};

#endif