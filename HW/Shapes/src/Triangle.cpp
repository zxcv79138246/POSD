#include "Triangle.h"
#include <math.h>

Triangle::Triangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY):
    firstX(firstX), firstY(firstY), secondX(secondX), secondY(secondY), thirdX(thirdX), thirdY(thirdY)
{
    this->sideLength1 = sqrt(pow(firstX-secondX,2) + pow (firstY-secondY,2));
    this->sideLength2 = sqrt(pow(secondX-thirdX,2) + pow (secondY-thirdY,2));
    this->sideLength3 = sqrt(pow(thirdX-firstX,2) + pow (thirdY-firstY,2));
    this->isValid = this->isTrangle(firstX, firstY, secondX, secondY, thirdX, thirdY);
}

Triangle::~Triangle()
{
    //dtor
}

bool Triangle::isTrangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY) {
    double m1,m2,m3;
    m1 = (firstX - secondX) / (firstY - secondY);
    m2 = (secondX - thirdX) / (secondY - thirdY);
    m3 = (thirdX - firstX) / (thirdY - firstY);

    if (m1 == m2 || m2 == m3 || m3 == m1){
        return false;
    }
    return true;
}

double Triangle::area() const {
    double s = ( sideLength1 + sideLength2 + sideLength3) / 2;
    double area = sqrt(s*(s-sideLength1)*(s-sideLength2)*(s-sideLength3));
    return area;
}

double Triangle::perimeter() const {
    return sideLength1 + sideLength2 + sideLength3;
}
