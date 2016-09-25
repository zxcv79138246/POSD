#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shapes.h"

class Rectangle: public Shapes
{
    public:
        Rectangle(double ulcx, double ulcy, double length, double width);
        virtual ~Rectangle();
        double area() const;
        double perimeter() const;

    protected:

    private:
        double x,y,length,width;
};

#endif // RECTANGLE_H
