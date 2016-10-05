#ifndef SHAPECALCULATE_H
#define SHAPECALCULATE_H

#include <vector>
#include "Shape.h"


class ShapeCalculate
{
    public:
        ShapeCalculate();
        virtual ~ShapeCalculate();
        double sumOfPerimeter(const vector<Shape *> &shapes);
        double sumOfArea(const vector<Shape *> &shapes);
        Shape* maxArea(const vector<Shape *> &shapes);
        void sortByDecreasingPerimeter(vector<Shape *> &shapes);

    protected:

    private:
};

#endif // SHAPECALCULATE_H
