#include <iostream>
#include "ShapeCalculate.h"

ShapeCalculate::ShapeCalculate()
{
    //ctor
}

ShapeCalculate::~ShapeCalculate()
{
    //dtor
}

double ShapeCalculate::sumOfPerimeter(vector<Shapes *> shapes) {
    double total = 0;
    for (Shapes *shap: shapes){
        total += shap->perimeter();
    }

    return total;
}
