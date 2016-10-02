#include "Triangle.h"
#include <math.h>

Triangle::Triangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY):
    firstX(firstX), firstY(firstY), secondX(secondX), secondY(secondY), thirdX(thirdX), thirdY(thirdY)
{
    this->sideLength1 = sqrt(pow(firstX-secondX,2) + pow (firstY-secondY,2));
    this->sideLength2 = sqrt(pow(secondX-thirdX,2) + pow (secondY-thirdY,2));
    this->sideLength3 = sqrt(pow(thirdX-firstX,2) + pow (thirdY-firstY,2));

    if (this->sideLength1 == 0 || this->sideLength2 == 0 || this->sideLength3 == 0){
      this->isValid = false;
    }else {
        this->isValid = true;
    }
}

Triangle::~Triangle()
{
    //dtor
}

double Triangle::area() const {
    double s = ( sideLength1 + sideLength2 + sideLength3) / 2;
    double area = sqrt(s*(s-sideLength1)*(s-sideLength2)*(s-sideLength3));
    return area;
}

double Triangle::perimeter() const {
    return sideLength1 + sideLength2 + sideLength3;
}
