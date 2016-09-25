#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

using namespace std;

class Shapes
{
    public:
        Shapes();
        virtual ~Shapes();
        virtual double area() const = 0;
        virtual double perimeter() const = 0;

    protected:

    private:
};

#endif // SHAPES_H
