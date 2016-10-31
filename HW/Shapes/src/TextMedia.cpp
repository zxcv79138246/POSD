#include "TextMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"


TextMedia::TextMedia(Rectangle boundingbox, string text): rectangle(boundingbox),text(text)
{
    //ctor
}

TextMedia::~TextMedia()
{
    //dtor
}

double TextMedia::area() {
    return this->rectangle.area() ;
}

double TextMedia::perimeter() {
    return this->rectangle.perimeter();
}

void TextMedia::accept(AreaVisitor& areaVisitor){

}

void TextMedia::accept(PerimeterVisitor& perimeterVisitor){

}

void TextMedia::accept(DescriptionVisitor* descriptionVisitor){

}

Rectangle TextMedia::getRectangle() const{
    return rectangle;
}

string TextMedia::getText() const{
    return text;
}
