#ifndef COMBOMEDIABUILDER_H
#define COMBOMEDIABUILDER_H

#include <MediaBuilder.h>

class ComboMediaBuilder: public MediaBuilder
{
    public:
        ComboMediaBuilder();
        virtual ~ComboMediaBuilder();
        void buildComboMedia();
        void buildComboMedia(Media * cm);
        void buildShapeMedia(Shape * s);
        Media *getMedia();

    protected:

    private:
        ComboMedia *combo;
};

#endif // COMBOMEDIABUILDER_H
