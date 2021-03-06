#include "Triangle.h"
#include <math.h>

Triangle::Triangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY, string name):
    firstX(firstX), firstY(firstY), secondX(secondX), secondY(secondY), thirdX(thirdX), thirdY(thirdY), name(name)
{
    this->sideLength1 = sqrt(pow(firstX-secondX,2) + pow (firstY-secondY,2));
    this->sideLength2 = sqrt(pow(secondX-thirdX,2) + pow (secondY-thirdY,2));
    this->sideLength3 = sqrt(pow(thirdX-firstX,2) + pow (thirdY-firstY,2));
}

Triangle::~Triangle()
{
    //dtor
}

bool Triangle::isTriangle() {
    if ((this->sideLength1+this->sideLength2>this->sideLength3) && (this->sideLength2+this->sideLength3>this->sideLength1)
        && (this->sideLength1+this->sideLength3>this->sideLength2)){
        return true;
    }else {
        throw string("Can not create triangle");
    }
}

double Triangle::area() const {
    double s = ( sideLength1 + sideLength2 + sideLength3) / 2;
    double area = sqrt(s*(s-sideLength1)*(s-sideLength2)*(s-sideLength3));
    return area;
}

double Triangle::perimeter() const {
    return sideLength1 + sideLength2 + sideLength3;
}

void Triangle:: setName(string name) {
    this->name = name;
}

string Triangle::getName() {
    return this->name;
}

string Triangle::description() const{
    std::stringstream ss;
    ss << "t(" << firstX << " " << firstY << " " << secondX << " " << secondY << " " << thirdX << " " << thirdY << ") ";
    return ss.str();
}

