#ifndef COMBOSHAPE_H
#define COMBOSHAPE_H

#include "Shape.h"
#include "ShapeCalculate.h"

class ComboShape : public Shape
{
    public:
        ComboShape(string comboName = "unknown");
        virtual ~ComboShape();
        void addShape(Shape* shape);
        double area() const;
        double perimeter() const;
        string description() const;
        void setName(string name);
        string getName();


    protected:

    private:
        string name;
        vector<Shape *> combo;
};

#endif // COMBOSHAPE_H
