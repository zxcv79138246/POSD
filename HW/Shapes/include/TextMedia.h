#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H

#include "Media.h"
#include "Text.h"

class AreaVisitor;
class PerimeterVisitor;
class DescriptionVisitor;
class TextVisitor;
class TextMedia: public Media
{
    public:
        TextMedia(Text text);
        virtual ~TextMedia();
        double area();
        double perimeter();
        void accept(AreaVisitor& areaVisitor);
        void accept(PerimeterVisitor& perimeterVisitor);
        void accept(DescriptionVisitor* descriptionVisitor);
        void accept(TextVisitor* textVisitor);
        void removeMedia(Media* m);
        Text getText() const;

    protected:

    private:
        Text text;
};

#endif // TEXTMEDIA_H
