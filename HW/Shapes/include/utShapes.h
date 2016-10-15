#include "../cppunitlite/TestHarness.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeCalculate.h"
#include "ComboShape.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "AreaVisitor.h"

using namespace std;

const double epsilon = 0.000001;

TEST(area, rectangle) {
    Rectangle rect(0,0,4,2, "rect");
    DOUBLES_EQUAL(8, rect.area(), epsilon);
}

TEST(perimeter, rectangle) {
    Rectangle rect(0,0,3,6, "rect");
    DOUBLES_EQUAL(18, rect.perimeter(), epsilon);
}

TEST(area, circle) {
    Circle circ(0,0,5,"circ");
    DOUBLES_EQUAL(75, circ.area(), epsilon);
}

TEST(perimeter, circle) {
    Circle circ(0,0,5, "circ");
    DOUBLES_EQUAL(30, circ.perimeter(), epsilon);
}

TEST (constructor1, triangle) {
    Triangle tri (0,0,1,1,2,2,"tri");
    try{
       tri.isTriangle();
    }catch(string s){
       CHECK(string("Can not create triangle")==s);
    }
}

TEST (constructor2, triangle) {
    Triangle tri (0,0,4,0,0,3,"tri");
    DOUBLES_EQUAL(4, tri.sideLength1, epsilon);
    DOUBLES_EQUAL(5, tri.sideLength2, epsilon);
    DOUBLES_EQUAL(3, tri.sideLength3, epsilon);
}

TEST (area, triangle) {
    Triangle tri (4,5,1,1,1,6,"tri");
    DOUBLES_EQUAL(7.5, tri.area(), epsilon)
}

TEST(perimeter, triangle) {
    Triangle tri (0,0,4,0,0,3,"tri");
    DOUBLES_EQUAL(12, tri.perimeter(), epsilon);

}

TEST(sumOfArea, shapes) {
    Rectangle r1(0,0,4,2,"r1");
    Circle c1(0,0,10, "c1");
    Triangle t1 (0,0,4,0,0,3,"tri");
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);
    DOUBLES_EQUAL(314, calculater.sumOfArea(shapesVector), epsilon)

}

TEST(sumOfPerimeter, shapes) {
    Rectangle r1(0,0,4,2,"r1");
    Circle c1(0,0,10, "c1");
    Triangle t1 (0,0,4,0,0,3,"tri");
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);
    DOUBLES_EQUAL(84, calculater.sumOfPerimeter(shapesVector), epsilon)

}

TEST(maxArea, shapes) {
    Rectangle r1(0,0,1,2,"r1");
    Circle c1(0,0,10, "c1");
    Triangle t1 (0,0,4,0,0,3,"tri");
    ShapeCalculate calculater;
    vector<Shape *> shapesVector;
    shapesVector.push_back(&r1);
    shapesVector.push_back(&c1);
    shapesVector.push_back(&t1);

    DOUBLES_EQUAL(300, calculater.maxArea(shapesVector)->area(), epsilon)
}

TEST(sortByDecreasingPerimeter, shapes) {
    Rectangle r1(0,0,6,2,"r1");  //16
    Circle c1(0,0,10, "c1");  //60
    Triangle t1 (0,0,4,0,0,3,"tri"); //12
    ShapeCalculate calculater;
    vector<Shape *> shapesVector = {&r1,&c1,&t1};
    calculater.sortByDecreasingPerimeter(shapesVector);
    vector<Shape *> hasShortedVector = {&c1,&r1,&t1};

    CHECK(hasShortedVector == shapesVector);
}

TEST (comboOfPerimeter, combo) {
    ShapeCalculate calculater;
    Rectangle r1(0,0,6,2,"r1");  //16
    Circle c1(0,0,10, "c1");  //60
    Triangle t1 (0,0,4,0,0,3,"tri"); //12
    ComboShape combo("combo1");
    combo.addShape(&r1);
    combo.addShape(&c1);
    combo.addShape(&t1);

    DOUBLES_EQUAL(88, combo.perimeter(), epsilon);
}

TEST (comboOfArea, combo) {
    ShapeCalculate calculater;
    Rectangle r1(0,0,6,2,"r1");  //12
    Circle c1(0,0,10, "c1");  //300
    Triangle t1 (0,0,4,0,0,3,"tri"); //6
    ComboShape combo("combo1");
    combo.addShape(&r1);
    combo.addShape(&c1);
    combo.addShape(&t1);

    DOUBLES_EQUAL(318, combo.area(), epsilon);
}

TEST (comboOfPerimeter2 ,combo) {
    ShapeCalculate calculater;
    Rectangle r1(0,0,6,2,"r1");  //16
    Circle c1(0,0,10, "c1");  //60
    Triangle t1 (0,0,4,0,0,3,"tri"); //12
    ComboShape combo("combo1");
    combo.addShape(&r1);
    combo.addShape(&c1);
    combo.addShape(&t1);

    Rectangle r2(0,0,1,3,"r2");  //8
    ComboShape combo2("combo2");
    combo2.addShape(&r2);
    combo2.addShape(&combo);

    DOUBLES_EQUAL(96, combo2.perimeter(), epsilon);
}

TEST (comboOfArea2 ,combo) {
    ShapeCalculate calculater;
    Rectangle r1(0,0,6,2,"r1");  //12
    Circle c1(0,0,10, "c1");  //300
    Triangle t1 (0,0,4,0,0,3,"tri"); //6
    ComboShape combo("combo1");
    combo.addShape(&r1);
    combo.addShape(&c1);
    combo.addShape(&t1);

    Rectangle r2(0,0,1,3,"r2");  //3
    ComboShape combo2("combo2");
    combo2.addShape(&r2);
    combo2.addShape(&combo);

    DOUBLES_EQUAL(321, combo2.area(), epsilon);
}

TEST (newShapeMediaArea ,shapeMedia) {
    Rectangle r1(0,0,6,2,"r1"); //12
    ShapeMedia rShapeMedia(&r1);

    DOUBLES_EQUAL(12, rShapeMedia.area(), epsilon)
}

TEST (newShapeMediaPerimeter ,shapeMedia) {
    Circle c1(0,0,10, "c1");  //60
    ShapeMedia cShapeMedia(&c1);

    DOUBLES_EQUAL(60, cShapeMedia.perimeter(), epsilon)
}

TEST (hexagonArea ,comboMedia) {
    Triangle t1 (0,4,3,0,3,8,"tri1"); //12
    Triangle t2 (11,4,8,0,8,8,"tri2"); //12
    Rectangle r1(3,8,5,8,"r1");  //40

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia hex;
    hex.add(&shapeMediaT1);
    hex.add(&shapeMediaT2);
    hex.add(&shapeMediaR1);

    DOUBLES_EQUAL(64, hex.area(), epsilon)
}

TEST (hexagonPerimeter ,comboMedia) {
    Triangle t1 (0,4,3,0,3,8,"tri1"); //18
    Triangle t2 (11,4,8,0,8,8,"tri2"); //18
    Rectangle r1(3,8,5,8,"r1");  //26

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia hex;
    hex.add(&shapeMediaT1);
    hex.add(&shapeMediaT2);
    hex.add(&shapeMediaR1);

    DOUBLES_EQUAL(62, hex.perimeter(), epsilon)
}

TEST (ShapeMedia ,AreaVisitor) {
    Triangle t1 (0,4,3,0,3,8,"tri1"); //12

    ShapeMedia shapeMediaT1(&t1);

    AreaVisitor areaVisitor;
    shapeMediaT1.accept(&areaVisitor);

    DOUBLES_EQUAL(12, areaVisitor.getArea(), epsilon)
}

TEST (ComboMedia ,AreaVisitor) {
    Triangle t1 (0,4,3,0,3,8,"tri1"); //12
    Triangle t2 (11,4,8,0,8,8,"tri2"); //12
    Rectangle r1(3,8,5,8,"r1");  //40

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia hex;
    hex.add(&shapeMediaT1);
    hex.add(&shapeMediaT2);
    hex.add(&shapeMediaR1);

    AreaVisitor areaVisitor;
    hex.accept(&areaVisitor);

    DOUBLES_EQUAL(64, areaVisitor.getArea(), epsilon)
}
