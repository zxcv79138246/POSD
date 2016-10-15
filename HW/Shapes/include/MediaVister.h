#ifndef MEDIAVISTER_H
#define MEDIAVISTER_H

#include "ShapeMedia.h"
#include "ComboMedia.h"

class MediaVister
{
    public:
        MediaVister();
        virtual ~MediaVister();
        virtual void visitShapeMedia(ShapeMedia *shapMedia) = 0;
        //virtual void visitComboMedia(ComboMedia *comboMedia) = 0;

    protected:

    private:
};

#endif // MEDIAVISTER_H
