#include "Circle.h"

Circle::Circle(double centerX, double centerY, double radius):cx(centerX),cy(centerY),radius(radius)
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

double Circle::area() const {
    return this->radius * this->radius * this->PI;
}

double Circle::perimeter() const {
    return this->radius * 2 * this->PI;
}
