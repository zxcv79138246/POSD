#ifndef SHAPEMEDIABUILDER_H
#define SHAPEMEDIABUILDER_H

#include <MediaBuilder.h>

class ShapeMediaBuilder: public MediaBuilder
{
    public:
        ShapeMediaBuilder();
        virtual ~ShapeMediaBuilder();
        void buildComboMedia();
        void buildComboMedia(Media * cm);
        void buildShapeMedia(Shape * s);
        Media *getMedia();

    protected:

    private:
        ShapeMedia *shapeMedia;
};

#endif // SHAPEMEDIABUILDER_H
