#include "TextVisitor.h"

TextVisitor::TextVisitor()
{
    //ctor
}

TextVisitor::~TextVisitor()
{
    //dtor
}

void TextVisitor::visitTextMedia(TextMedia *textMedia){
    text = (textMedia->getText()).getText();
}

string TextVisitor::getText() {
    return text;
}
