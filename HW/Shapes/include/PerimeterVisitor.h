#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H

#include "MediaVisitor.h"

class PerimeterVisitor: public MediaVisitor
{
    public:
        PerimeterVisitor();
        virtual ~PerimeterVisitor();
        void visitShapeMedia(ShapeMedia *shapeMedia);
        void visitComboMedia(ComboMedia *comboMedia);
        double getPerimeter() const;

    protected:

    private:
        double perimeter = 0;
};

#endif // PERIMETERVISITOR_H
