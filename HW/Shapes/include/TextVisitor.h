#ifndef TEXTVISITOR_H
#define TEXTVISITOR_H

#include "MediaVisitor.h"

class TextVisitor: public MediaVisitor
{
    public:
        TextVisitor();
        virtual ~TextVisitor();
        void visitShapeMedia(ShapeMedia *shapeMedia){};
        void visitComboMedia(ComboMedia *comboMedia){};
        void visitTextMedia(TextMedia *textMedia);
        string getText();

    protected:

    private:
        string text;
};

#endif // TEXTVISITOR_H
