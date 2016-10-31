#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape
{
    public:
        Triangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY, string name);
        virtual ~Triangle();
        double area() const;
        double perimeter() const;
        string description() const;
        double sideLength1,sideLength2,sideLength3;
        bool isTriangle();
        void setName(string name);
        string getName();

    protected:

    private:
        string name;
        double firstX, firstY, secondX, secondY, thirdX, thirdY;

};

#endif // TRIANGLE_H
