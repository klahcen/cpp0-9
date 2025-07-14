

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point(Fixed const x, Fixed const y);
        Point(const Point& copy);
        ~Point();
        Point& operator= (const Point& other);
        Fixed get_xpoint() const;
        Fixed get_ypoint() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif