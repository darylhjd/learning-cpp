#include "Point2d.h"
#include <iostream>
#include <cmath>

double distance_from(const Point2d& p1, const Point2d& p2) {
    return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " 
    << distance_from(first, second) << '\n';

    return 0;
}