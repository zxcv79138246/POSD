#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle: public Shape
{
    public:
        Circle(double centerX, double centerY, double radius, string name);
        virtual ~Circle();
        double area() const;
        double perimeter() const;
        string description() const;
        void setName(string name);
        string getName();

    protected:
        string name;

    private:
        double cx,cy,radius;
        const double PI = 3;
};

#endif // CIRCLE_H
