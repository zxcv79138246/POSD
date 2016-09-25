#include "../cppunitlite/TestHarness.h"
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

TEST (constructor, triangle) {
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

TEST(sumOfPerimeter, shapes) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1 (0,0,4,0,0,3);
    ShapeCalculate calculater;
    vector<Shapes *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);
    DOUBLES_EQUAL(84, calculater.sumOfPerimeter(shapesVector), epsilon)

}
