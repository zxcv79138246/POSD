#include "Circle.h"

Circle::Circle(double centerX, double centerY, double radius, string name):
    cx(centerX),cy(centerY),radius(radius),name(name)
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

void Circle:: setName(string name) {
    this->name = name;
}

string Circle::getName() {
    return this->name;
}
