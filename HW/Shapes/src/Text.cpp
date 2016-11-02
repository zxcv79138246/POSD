#include "Text.h"

Text::Text(Rectangle boundingbox, string text): rectangle(boundingbox),text(text)
{
    //ctor
}

Text::~Text()
{
    //dtor
}

Rectangle Text::getRectangle() const{
    return rectangle;
}

string Text::getText() const{
    return text;
}
