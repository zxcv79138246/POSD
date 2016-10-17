#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "MediaVisitor.h"

class AreaVisitor: public MediaVisitor
{
    public:
        AreaVisitor();
        virtual ~AreaVisitor();
        void visitShapeMedia(ShapeMedia *shapeMedia);
        void visitComboMedia(ComboMedia *comboMedia);
        double getArea() const;

    protected:

    private:
        double area = 0;
};

#endif // AREAVISITOR_H
