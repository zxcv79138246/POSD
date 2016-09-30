#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle: public Shape
{
    public:
        Circle(double centerX, double centerY, double radius);
        virtual ~Circle();
        double area() const;
        double perimeter() const;

    protected:

    private:
        double cx,cy,radius;
        const double PI = 3;
};

#endif // CIRCLE_H
