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
    for (Media *m: comboMedia->getCombo()){
        m->accept(this);
    }
}

double AreaVisitor::getArea() const {
    return area;
}
