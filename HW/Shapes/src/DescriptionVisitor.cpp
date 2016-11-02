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

void DescriptionVisitor::visitComboMediaPre(ComboMedia *comboMedia){
    description = description + string("combo(");
}

void DescriptionVisitor::visitComboMediaPost(ComboMedia *comboMedia){
    description = description + string(")");
}

string DescriptionVisitor::getDescription() const {
    return description;
}
