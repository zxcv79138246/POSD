#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "ShapeMedia.h"
#include "ComboMedia.h"

class ShapeMedia;
class ComboMedia;
class AreaVisitor
{
    public:
        AreaVisitor();
        virtual ~AreaVisitor();
        void visitShapeMedia(ShapeMedia *shapeMedia);
        void visitComboMedia(ComboMedia *comboMedia);
        double getArea() const;

    protected:

    private:
        double area;
};

#endif // AREAVISITOR_H
