#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H

#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"
#include "Text.h"
#include <String>

class MediaVisitor
{
    public:
        MediaVisitor();
        virtual ~MediaVisitor();
        virtual void visitShapeMedia(ShapeMedia *shapMedia) = 0;
        virtual void visitComboMedia(ComboMedia *comboMedia) = 0;
        virtual void visitComboMediaPre(ComboMedia *comboMedia) = 0;
        virtual void visitComboMediaPost(ComboMedia *comboMedia) = 0;
        virtual void visitTextMedia(TextMedia *textMedia) = 0;

    protected:

    private:
};

#endif // MEDIAVISITOR_H
