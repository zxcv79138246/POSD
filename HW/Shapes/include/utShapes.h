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
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "TextMedia.h"
#include <stack>

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
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1"); //1.732050
    Triangle t2 (2, 2*sqrt(3), 2, 0, 3, sqrt(3), "tri2"); //1.732050
    Rectangle r1(0, 2*sqrt(3), 2, 2*sqrt(3),"r1");  //6.928230

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia hex;
    hex.add(&shapeMediaT1);
    hex.add(&shapeMediaT2);
    hex.add(&shapeMediaR1);

    DOUBLES_EQUAL(10.392305, hex.area(), epsilon)
}

TEST (hexagonPerimeter ,comboMedia) {
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1");//7.464101
    Triangle t2 (2, 2*sqrt(3), 2, 0, 3, sqrt(3), "tri2"); //7.464101
    Rectangle r1(0, 2*sqrt(3), 2, 2*sqrt(3),"r1");  //10.928203

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia hex;
    hex.add(&shapeMediaT1);
    hex.add(&shapeMediaT2);
    hex.add(&shapeMediaR1);

    DOUBLES_EQUAL(25.856406, hex.perimeter(), epsilon)
}

TEST (ShapeMedia ,AreaVisitor) {
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1"); //1.732050

    ShapeMedia shapeMediaT1(&t1);

    AreaVisitor areaVisitor;
    shapeMediaT1.accept(areaVisitor);

    DOUBLES_EQUAL(1.732050, areaVisitor.getArea(), epsilon)
}

TEST (ShapeMedia ,PerimeterVisitor) {
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1");//7.464101

    ShapeMedia shapeMediaT1(&t1);

    PerimeterVisitor perimeterVisitor;
    shapeMediaT1.accept(perimeterVisitor);

    DOUBLES_EQUAL(7.464101, perimeterVisitor.getPerimeter(), epsilon)
}

TEST (ComboMedia ,AreaVisitor) {
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1"); //1.732050
    Triangle t2 (2, 2*sqrt(3), 2, 0, 3, sqrt(3), "tri2"); //1.732050
    Rectangle r1(0, 2*sqrt(3), 2, 2*sqrt(3),"r1");  //6.928230

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia combo1;
    combo1.add(&shapeMediaT1);
    combo1.add(&shapeMediaR1);

    ComboMedia combo2;
    combo2.add(&combo1);
    combo2.add(&shapeMediaT2);

    AreaVisitor areaVisitor;
    combo2.accept(areaVisitor);

    DOUBLES_EQUAL(10.392305, areaVisitor.getArea(), epsilon)
}

TEST (ComboMedia ,PerimeterVisitor) {
    Triangle t1 (0, 2*sqrt(3), -1, sqrt(3),0,0,"tri1");//7.464101
    Triangle t2 (2, 2*sqrt(3), 2, 0, 3, sqrt(3), "tri2"); //7.464101
    Rectangle r1(0, 2*sqrt(3), 2, 2*sqrt(3),"r1");  //10.928203

    ShapeMedia shapeMediaT1(&t1);
    ShapeMedia shapeMediaT2(&t2);
    ShapeMedia shapeMediaR1(&r1);

    ComboMedia combo1;
    combo1.add(&shapeMediaT1);
    combo1.add(&shapeMediaR1);

    ComboMedia combo2;
    combo2.add(&combo1);
    combo2.add(&shapeMediaT2);

    PerimeterVisitor perimeterVisitor;
    combo2.accept(perimeterVisitor);

    DOUBLES_EQUAL(25.856406, perimeterVisitor.getPerimeter(), epsilon)
}

TEST (Circle ,DescriptionVisitor) {
    DescriptionVisitor descriptionVisitor;
    Circle c1(0,0,5, "c1");
    ShapeMedia shapeMediaC1(&c1);
    shapeMediaC1.accept(&descriptionVisitor);
    CHECK(string("c(0 0 5) ") == descriptionVisitor.getDescription());

}

TEST (BuildFalse ,ShapeMediaBuilder) {
    ShapeMediaBuilder smb;
    Circle c1(0,0,5, "c1");
    try{
        smb.buildShapeMedia(&c1);
    }catch(string s) {
        CHECK(string("null point ex") == s);
    }
}

TEST (Circle ,ShapeMediaBuilder) {
    DescriptionVisitor descriptionVisitor;
    ShapeMediaBuilder smb;
    Circle c1(0,0,5, "c1");
    smb.buildShapeMedia(&c1);
    smb.getMedia()->accept(&descriptionVisitor);
    CHECK(string("c(0 0 5) ") == descriptionVisitor.getDescription());
}

TEST (BuildHouse ,ComboMediaBuilder) {
    DescriptionVisitor descriptionVisitor;
    stack<MediaBuilder *> mbs;
    mbs.push(new ComboMediaBuilder());
    mbs.push(new ComboMediaBuilder());
    mbs.push(new ComboMediaBuilder());
    Rectangle r1(10, 0, 15, 5,"r1");
    mbs.top()->buildShapeMedia(&r1);
    Circle c1(12,5,2, "c1");
    mbs.top()->buildShapeMedia(&c1);
    Media* cm1 = mbs.top()->getMedia();
    mbs.pop();

    mbs.top()->buildComboMedia(cm1);
    Rectangle r2(0, 0, 25, 20,"r2");
    mbs.top()->buildShapeMedia(&r2);
    Media* cm2 = mbs.top()->getMedia();
    mbs.pop();

    mbs.top()->buildComboMedia(cm2);
    Triangle t1(0, 20, 16, 32, 25, 20, "t1");
    mbs.top()->buildShapeMedia(&t1);

    mbs.top()->getMedia()->accept(&descriptionVisitor);

    CHECK(string("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )") == descriptionVisitor.getDescription());
}

TEST (TextMedia ,TextMedia) {
    Rectangle r1(10, 0, 15, 5,"r1");
    string text = string("test");
    TextMedia textMedia(r1, text);

   CHECK(string("test") == textMedia.getText());
}
