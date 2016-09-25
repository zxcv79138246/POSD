#include "Rectangle.h"

Rectangle::Rectangle(double ulcx, double ulcy, double length, double width):x(ulcx),y(ulcy),length(length),width(width)
{
    //ctor
}

Rectangle::~Rectangle()
{
    //dtor
}

double Rectangle::area() const {
    return this->length * this->width;
}

double Rectangle::perimeter() const {
    return (this->length + this->width) *2;
}
