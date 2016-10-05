#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(double ulcx, double ulcy, double length, double width, string name):
    x(ulcx),y(ulcy),length(length),width(width),name(name)
{

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

void Rectangle:: setName(string name) {
    this->name = name;
}

string Rectangle::getName() {
    return this->name;
}

