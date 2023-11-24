#pragma once
#include "Point.h"
class Point_2D :
    public Point
{
public:
    double x, y;
    Point_2D() : x(0), y(0) {}
    Point_2D(double x, double y) : x(x), y(y) {}
    Point_2D(const Point_2D& point) : x(point.x), y(point.y) {}
    std::string to_string()
    {
        std::string str = std::to_string(x) + ' ' + std::to_string(y);
        return str;
    }
    Point_2D operator +(const Point_2D& point)
    {
        return Point_2D(x + point.x, y + point.y);
    }
    Point_2D operator *(const double a)
    {
        return Point_2D(x * a, y * a);
    }
};

