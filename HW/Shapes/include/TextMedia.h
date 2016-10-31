#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H

#include "Media.h"
#include "Shape.h"
#include "Rectangle.h"

class AreaVisitor;
class PerimeterVisitor;
class DescriptionVisitor;
class TextMedia: public Media
{
    public:
        TextMedia(Rectangle boundingbox, string text);
        virtual ~TextMedia();
        double area();
        double perimeter();
        void accept(AreaVisitor& areaVisitor);
        void accept(PerimeterVisitor& perimeterVisitor);
        void accept(DescriptionVisitor* descriptionVisitor);
        Rectangle getRectangle() const;
        string getText() const;

    protected:

    private:
        Rectangle rectangle;
        string text;
};

#endif // TEXTMEDIA_H
