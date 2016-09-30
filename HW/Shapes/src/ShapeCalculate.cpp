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

double ShapeCalculate::sumOfPerimeter(const vector<Shape *> &shapes) {
    double total = 0;
    for (Shape *shap: shapes){
        total += shap->perimeter();
    }

    return total;
}

double ShapeCalculate::sumOfArea(const vector<Shape *> &shapes) {
    double total = 0;
    for (Shape *shap: shapes){
        total += shap->area();
    }

    return total;
}
