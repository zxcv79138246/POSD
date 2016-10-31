#include "ShapeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

ShapeMedia::ShapeMedia(Shape* s): shape(s)
{

}

ShapeMedia::~ShapeMedia()
{
    //dtor
}


double ShapeMedia::area() {
    return this->shape->area();
}

double ShapeMedia::perimeter() {
    return this->shape->perimeter();
}

void ShapeMedia::accept(AreaVisitor& areaVisitor){
    areaVisitor.visitShapeMedia(this);
}

Shape* ShapeMedia::getShape(){
    return shape;
}

void ShapeMedia::accept(PerimeterVisitor& perimeterVisitor){
    perimeterVisitor.visitShapeMedia(this);
}

void ShapeMedia::accept(DescriptionVisitor* descriptionVisitor){
    descriptionVisitor->visitShapeMedia(this);
}

