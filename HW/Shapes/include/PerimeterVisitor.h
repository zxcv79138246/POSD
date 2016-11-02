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
        void visitComboMediaPre(ComboMedia *comboMedia){};
        void visitComboMediaPost(ComboMedia *comboMedia){};
        void visitTextMedia(TextMedia *textMedia){};
        double getPerimeter() const;

    protected:

    private:
        double perimeter = 0;
};

#endif // PERIMETERVISITOR_H
