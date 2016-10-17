#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor()
{
    //ctor
}

PerimeterVisitor::~PerimeterVisitor()
{
    //dtor
}

void PerimeterVisitor::visitShapeMedia(ShapeMedia *shapeMedia){
    perimeter += shapeMedia->getShape()->perimeter();
}

void PerimeterVisitor::visitComboMedia(ComboMedia *comboMedia){
}

double PerimeterVisitor::getPerimeter() const{
    return perimeter;
}
