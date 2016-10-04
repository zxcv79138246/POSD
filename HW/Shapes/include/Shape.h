#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

using namespace std;

class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        //virtual void getName() = 0;

    protected:
        string name;

    private:
};

#endif // SHAPE_H
