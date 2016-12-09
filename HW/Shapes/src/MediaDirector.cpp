#include "MediaDirector.h"

MediaDirector::MediaDirector()
{
    //ctor
}

MediaDirector::~MediaDirector()
{
    //dtor
}

void MediaDirector::setMediaBuilder(std::stack<MediaBuilder *> *mbs){
    mb = mbs;
}

void MediaDirector::concrete(string content){
    mb->push(new ShapeMediaBuilder());
    for (int i; i<content.size(); i++) {
        switch(content[i]) {
            case 'r':
            case 'c':
            case 't':
            {
                if (content[i+1] == 'o'){
                    if (i==0) {
                        mb->pop();
                    }
                    mb->push(new ComboMediaBuilder());
                    break;
                }else {
                    if (content[i] == 'r') {
                        size_t rightEnd = content.find(")", i);
                        mb->top()->buildShapeMedia(makeRec(content.substr(i+2, rightEnd-i-2)));
                        i = rightEnd;
                    }else if (content[i] == 'c') {
                        size_t rightEnd = content.find(")", i);
                        mb->top()->buildShapeMedia(makeCir(content.substr(i+2, rightEnd-i-2)));
                        i = rightEnd;
                    }else if (content[i] == 't') {
                        size_t rightEnd = content.find(")", i);
                        mb->top()->buildShapeMedia(makeTri(content.substr(i+2, rightEnd-i-2)));
                        i = rightEnd;
                    }
                }
                break;
            }
            case ')' :{
                if (mb->size() > 1){
                    Media* cm1 = mb->top()->getMedia();
                    mb->pop();
                    mb->top()->buildComboMedia(cm1);
                }
                break;
            }
        }
    }
}

Rectangle* MediaDirector::makeRec(string rec){
    stringstream ss(rec);
    string subStr;
    double num[4];
    int i=0;
    while(getline(ss,subStr,' ')){
        stringstream(subStr) >> num[i];
        i++;
    }

    Rectangle* r = new Rectangle(num[0], num[1], num[2], num[3], "R");

    return r;
}

Circle* MediaDirector::makeCir(string cir){
    stringstream ss(cir);
    string subStr;
    double num[3];
    int i=0;
    while(getline(ss,subStr,' ')){
        stringstream(subStr) >> num[i];
        i++;
    }

    Circle* c = new Circle(num[0], num[1], num[2], "C");

    return c;
}

Triangle* MediaDirector::makeTri(string tri){
    stringstream ss(tri);
    string subStr;
    double num[6];
    int i=0;
    while(getline(ss,subStr,' ')){
        stringstream(subStr) >> num[i];
        i++;
    }

    Triangle* t = new Triangle(num[0], num[1], num[2], num[3], num[4], num[5], "T");

    return t;
}


