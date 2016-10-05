#include <iostream>
#include "ShapeCalculate.h"
#include <algorithm>

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

Shape *ShapeCalculate::maxArea(const vector<Shape *> &shapes) {
    Shape *resultShape;
    double resultArea = 0;
    for (Shape *shape: shapes){
        if (shape->area() > resultArea) {
            resultArea = shape->area();
            resultShape = shape;
        }
    }

    return resultShape;
}

void ShapeCalculate::sortByDecreasingPerimeter(vector<Shape *> &shapes) {
    sort (shapes.begin(), shapes.end(), [](Shape*shape1,Shape* shape2){
            return shape1->perimeter() > shape2->perimeter();
          });
}
