

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        float x;
        float y;
    public:
        Point();
        Point(float const x, float const y);
        Point(const Point& copy);
        ~Point();
        Point& operator= (const Point& other);
        float get_xpoint() const;
        float get_ypoint() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif