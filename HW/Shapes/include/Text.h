#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Shape.h"
#include "Rectangle.h"

class Text
{
    public:
        Text(Rectangle boundingbox, string text);
        virtual ~Text();
        Rectangle getRectangle() const;
        string getText() const;

    protected:

    private:
        Rectangle rectangle;
        string text;
};

#endif // TEXT_H
