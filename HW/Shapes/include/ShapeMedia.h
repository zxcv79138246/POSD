#ifndef SHAPEMEDIA_H
#define SHAPEMEDIA_H

#include "Media.h"
#include "Shape.h"

class AreaVisitor;
class PerimeterVisitor;
class ShapeMedia: public Media
{
    public:
        ShapeMedia(Shape* s);
        virtual ~ShapeMedia();
        double area();
        double perimeter();
        void accept(AreaVisitor& areaVisitor);
        void accept(PerimeterVisitor& perimeterVisitor);
        Shape* getShape();

    protected:

    private:
        Shape* shape ;
};

#endif // SHAPEMEDIA_H
