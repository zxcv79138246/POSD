#include "ComboMediaBuilder.h"
#include <iostream>

ComboMediaBuilder::ComboMediaBuilder()
{
    combo = new ComboMedia;
}

ComboMediaBuilder::~ComboMediaBuilder()
{
    //dtor
}

void ComboMediaBuilder::buildComboMedia(){

}

void ComboMediaBuilder::buildComboMedia(Media * cm){
    combo->add(cm);
}

void ComboMediaBuilder::buildShapeMedia(Shape * s){
    if(!combo){
        throw string("null point ex") ;
    }
    combo->add(new ShapeMedia(s));
}


Media *ComboMediaBuilder::getMedia(){
    return combo;
}
