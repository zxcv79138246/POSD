#include "AreaVisitor.h"

AreaVisitor::AreaVisitor()
{
    //ctor
}

AreaVisitor::~AreaVisitor()
{
    //dtor
}

void AreaVisitor::visitShapeMedia(ShapeMedia *shapeMedia) {
    area += shapeMedia->getShape()->area();
}

void AreaVisitor::visitComboMedia(ComboMedia *comboMedia){

}

double AreaVisitor::getArea() const {
    return area;
}
