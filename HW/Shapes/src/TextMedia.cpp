#include "TextMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "TextVisitor.h"


TextMedia::TextMedia(Text text): text(text)
{
    //ctor
}

TextMedia::~TextMedia()
{
    //dtor
}

double TextMedia::area() {

}

double TextMedia::perimeter() {

}

void TextMedia::accept(AreaVisitor& areaVisitor){

}

void TextMedia::accept(PerimeterVisitor& perimeterVisitor){

}

void TextMedia::accept(DescriptionVisitor* descriptionVisitor){

}

void TextMedia::accept(TextVisitor* textVisitor){
    textVisitor->visitTextMedia(this);
}

Text TextMedia::getText() const{
    return text;
}

void TextMedia::removeMedia(Media* m){
}

void TextMedia::add(Media* m){
}
