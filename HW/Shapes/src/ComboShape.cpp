#include "ComboShape.h"

ComboShape::ComboShape(string comboName):name(comboName)
{
    //ctor
}

ComboShape::~ComboShape()
{
    //dtor
}

void ComboShape::addShape(Shape* shape) {
    combo.push_back(shape);
}

double ComboShape::area() const {
    ShapeCalculate calculate;

    return calculate.sumOfArea(this->combo);
}

double ComboShape::perimeter() const {
    ShapeCalculate calculate;

    return calculate.sumOfPerimeter(this->combo);
}

void ComboShape:: setName(string name) {
    this->name = name;
}

string ComboShape::getName() {
    return this->name;
}

