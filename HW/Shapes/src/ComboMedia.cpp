#include "ComboMedia.h"

ComboMedia::ComboMedia()
{
    //ctor
}

ComboMedia::~ComboMedia()
{
    //dtor
}

void ComboMedia::add(Media* media) {
    combo.push_back(media);
}

double ComboMedia::area(){
    double total =0;
    for (Media *m: combo){
        total += m->area();
    }

    return total;
}

double ComboMedia::perimeter(){
    double total =0;
    for (Media *m: combo){
        total += m->perimeter();
    }

    return total;
}

void ComboMedia::accept(AreaVisitor* areaVisitor){
    areaVisitor->visitComboMedia(this);
}

vector<Media*> ComboMedia::getCombo(){
    return combo;
}
