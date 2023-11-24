#pragma once
#include "Point.h"
#include <iostream>
class Point_3D :
    public Point
{
public:
    double x, y, z;
    Point_3D() : x(0), y(0), z(0) {}
    Point_3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Point_3D(const Point_3D& point) : x(point.x), y(point.y), z(point.z) {}
    std::string to_string()
    {
        std::string str = std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z);
        return str;
    }
    int point_type()
    {
        return 3;
    }
    Point_3D& operator =(const Point_3D& point)
    {
        x = point.x;
        y = point.y;
        z = point.z;
        return *this;

    }
    Point_3D operator+ (const Point_3D& point)
    {
        return Point_3D(x + point.x, y + point.y, z + point.z);
    }
    Point_3D operator *(const double a)
    {
        return Point_3D(x * a, y * a, z * a);
    }

};


