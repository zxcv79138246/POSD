#ifndef MEDIABUILDER_H
#define MEDIABUILDER_H

#include "Shape.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "DescriptionVisitor.h"

class MediaBuilder
{
    public:
        MediaBuilder();
        virtual ~MediaBuilder();
        virtual void buildComboMedia() = 0;
        virtual void buildComboMedia(Media * cm) = 0;
        virtual void buildShapeMedia(Shape * s) = 0;
        virtual Media *getMedia()= 0;

    protected:

    private:
};

#endif // MEDIABUILDER_H
