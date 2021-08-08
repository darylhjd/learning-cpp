#ifndef POINT_2D
#define POINT_2D

class Point2d {
    double m_x{0.0};
    double m_y{0.0};

public:
    Point2d(double x=0.0, double y=0.0);

    void print() const;
    double distance_to(const Point2d& p) const;

    friend double distance_from(const Point2d& p1, const Point2d& p2);
};

#endif