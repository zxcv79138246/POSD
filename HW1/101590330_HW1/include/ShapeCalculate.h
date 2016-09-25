#ifndef SHAPECALCULATE_H
#define SHAPECALCULATE_H

#include <vector>
#include "Shapes.h"


class ShapeCalculate
{
    public:
        ShapeCalculate();
        virtual ~ShapeCalculate();
        double sumOfPerimeter(vector<Shapes *> shapes);

    protected:

    private:
};

#endif // SHAPECALCULATE_H
