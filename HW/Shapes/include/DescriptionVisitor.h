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
        void visitComboMediaPre(ComboMedia *comboMedia);
        void visitComboMediaPost(ComboMedia *comboMedia);
        void visitTextMedia(TextMedia *textMedia){};
        string getDescription() const;

    protected:

    private:
        string description;
};

#endif // DESCRIPTIONVISITOR_H
