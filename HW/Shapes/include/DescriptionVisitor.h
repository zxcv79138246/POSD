#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H

#include "MediaVisitor.h"


class DescriptionVisitor: public MediaVisitor
{
    public:
        DescriptionVisitor();
        virtual ~DescriptionVisitor();
        void visitShapeMedia(ShapeMedia *shapeMedia);
        void visitComboMedia(ComboMedia *comboMedia);
        string getDescription() const;

    protected:

    private:
        string description;
};

#endif // DESCRIPTIONVISITOR_H
