#include "ComboMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

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

void ComboMedia::accept(AreaVisitor& areaVisitor){
    for (Media *m: combo){
        m->accept(areaVisitor);
    }
}

void ComboMedia::accept(PerimeterVisitor& perimeterVisitor){
    for (Media *m: combo){
        m->accept(perimeterVisitor);
    }
}
