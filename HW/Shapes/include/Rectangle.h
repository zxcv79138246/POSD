#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <string>

using namespace std;

class Rectangle: public Shape
{
    public:
        Rectangle(double ulcx, double ulcy, double length, double width, string name);
        virtual ~Rectangle();
        double area() const;
        double perimeter() const;
        void setName(string name);
        string getName();

    protected:

    private:
        string name;
        double x,y,length,width;
};

#endif // RECTANGLE_H
