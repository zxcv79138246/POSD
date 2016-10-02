#include "../cppunitlite/TestHarness.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeCalculate.h"

using namespace std;

const double epsilon = 0.000001;

TEST(area, rectangle) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8, rect.area(), epsilon);
}

TEST(perimeter, rectangle) {
    Rectangle rect(0,0,3,6);
    DOUBLES_EQUAL(18, rect.perimeter(), epsilon);
}

TEST(area, circle) {
    Circle circ(0,0,5);
    DOUBLES_EQUAL(75, circ.area(), epsilon);
}

TEST(perimeter, circle) {
    Circle circ(0,0,5);
    DOUBLES_EQUAL(30, circ.perimeter(), epsilon);
}

TEST (constructor1, triangle) {
    Triangle tri (0,0,1,1,2,2);
    if (!tri.isValid){
        FAIL("Not a triangle");
    }
}

TEST (constructor2, triangle) {
    Triangle tri (0,0,4,0,0,3);
    DOUBLES_EQUAL(4, tri.sideLength1, epsilon);
    DOUBLES_EQUAL(5, tri.sideLength2, epsilon);
    DOUBLES_EQUAL(3, tri.sideLength3, epsilon);
}

TEST (area, triangle) {
    Triangle tri (4,5,1,1,1,6);
    DOUBLES_EQUAL(7.5, tri.area(), epsilon)
}

TEST(perimeter, triangle) {
    Triangle tri (0,0,4,0,0,3);
    DOUBLES_EQUAL(12, tri.perimeter(), epsilon);

}

TEST(sumOfArea, shapes) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1 (0,0,4,0,0,3);
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);
    DOUBLES_EQUAL(314, calculater.sumOfArea(shapesVector), epsilon)

}

TEST(sumOfPerimeter, shapes) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1 (0,0,4,0,0,3);
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);
    DOUBLES_EQUAL(84, calculater.sumOfPerimeter(shapesVector), epsilon)

}

TEST(maxArea, shapes) {
    Rectangle r1(0,0,1,2);
    Circle c1(0,0,10);
    Triangle t1 (0,0,4,0,0,3);
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);

    DOUBLES_EQUAL(300, calculater.maxArea(shapesVector)->area(), epsilon)
}

TEST(sortByDecreasingPerimeter, shapes) {
    Rectangle r1(0,0,6,2);
    Circle c1(0,0,10);
    Triangle t1 (0,0,4,0,0,3);
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);

    double result[] = {60,16,12};
    int i = 0;
    for (Shape* shape: calculater.sortByDecreasingPerimeter(shapesVector)){
        DOUBLES_EQUAL(result[i], shape->perimeter(), epsilon);
        i++;
    }

}
