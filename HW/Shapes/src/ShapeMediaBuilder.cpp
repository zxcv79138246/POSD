#include "ShapeMediaBuilder.h"

ShapeMediaBuilder::ShapeMediaBuilder()
{

}

ShapeMediaBuilder::~ShapeMediaBuilder()
{
    //dtor
}

void ShapeMediaBuilder::buildComboMedia(){

}

void ShapeMediaBuilder::buildComboMedia(Media * cm){
}

void ShapeMediaBuilder::buildShapeMedia(Shape * s){
//    if(!shapeMedia){
//        throw string("null point ex") ;
//    }
    shapeMedia = new ShapeMedia(s);
}

Media *ShapeMediaBuilder::getMedia(){
    return shapeMedia;
}

