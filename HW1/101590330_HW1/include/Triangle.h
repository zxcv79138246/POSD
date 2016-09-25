#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"

class Triangle: public Shapes
{
    public:
        Triangle(double firstX, double firstY, double secondX, double secondY, double thirdX, double thirdY);
        virtual ~Triangle();
        double area() const;
        double perimeter() const;
        double sideLength1,sideLength2,sideLength3;

    protected:

    private:
        double firstX, firstY, secondX, secondY, thirdX, thirdY;
};

#endif // TRIANGLE_H
