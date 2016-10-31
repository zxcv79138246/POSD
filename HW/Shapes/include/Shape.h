#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual string description() const = 0;
        virtual void setName(string name) = 0;
        virtual string getName() = 0;



    protected:
        string name;
        string desc;

    private:


};

#endif // SHAPE_H
