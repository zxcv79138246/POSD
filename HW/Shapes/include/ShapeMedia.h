#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H

#include "Media.h"
#include "Shape.h"
#include "AreaVisitor.h"

class AreaVisitor;
class ShapeMedia: public Media
{
    public:
        ShapeMedia(Shape* s);
        virtual ~ShapeMedia();
        double area();
        double perimeter();
        void accept(AreaVisitor* areaVisitor);
        Shape* getShape();

    protected:

    private:
        Shape* shape ;
};

#endif // SHAPEMEDIA_H
