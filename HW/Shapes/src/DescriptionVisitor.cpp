#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor()
{
    //ctor
}

DescriptionVisitor::~DescriptionVisitor()
{
    //dtor
}

void DescriptionVisitor::visitShapeMedia(ShapeMedia *shapeMedia){
    description += shapeMedia->getShape()->description();
}

void DescriptionVisitor::visitComboMedia(ComboMedia *comboMedia){
    description = string("combo(") + description + string(")");
}

string DescriptionVisitor::getDescription() const {
    return description;
}
