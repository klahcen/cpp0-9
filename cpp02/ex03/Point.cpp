

#include "Point.hpp"

Point::Point(){
    this->x= 0;
    this->x= 0;
}
Point::Point(float const x, float const y){
    this->x = x;
    this->y = y;
}

Point::Point(const Point& copy){
    this->x = copy.x;
    this->y = copy.y;
}
Point::~Point(){

}
Point& Point::operator= (const Point& other){
    this->x = other.x;
    this->y = other.y;
    return *this;
}

float Point::get_xpoint() const {
    return this->x;
}

float Point::get_ypoint() const {
    return this->y;
}