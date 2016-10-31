#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H

#include "ShapeMedia.h"
#include "ComboMedia.h"
#include <String>

class MediaVisitor
{
    public:
        MediaVisitor();
        virtual ~MediaVisitor();
        virtual void visitShapeMedia(ShapeMedia *shapMedia) = 0;
        virtual void visitComboMedia(ComboMedia *comboMedia) = 0;

    protected:

    private:
};

#endif // MEDIAVISITOR_H
