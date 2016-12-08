#include "ComboMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

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

void ComboMedia::accept(DescriptionVisitor* descriptionVisitor){
    descriptionVisitor->visitComboMediaPre(this);
    for (Media *m: combo){
        m->accept(descriptionVisitor);
    }
    descriptionVisitor->visitComboMediaPost(this);
}

bool isCombo(Media* m) {
    DescriptionVisitor dv;
    m->accept(&dv);
    if (!(dv.getDescription()).find("combo")){
        return true;
    }
    return false;

}

void ComboMedia::removeMedia(Media* m) {
    DescriptionVisitor descriptionVisitor;
    DescriptionVisitor removeDV;
    m->accept(&removeDV);
    string removeDesc = removeDV.getDescription();
    for (vector<Media*>::iterator it = combo.begin(); it!= combo.end(); it++){
        DescriptionVisitor itDV;
        (*it)->accept(&itDV);
        if (isCombo(*it)){
            (*it)->removeMedia(m);
        }else {
            if (itDV.getDescription() == removeDesc){
                combo.erase(it);
                break;
            }
        }
    }
}

vector<Media*> ComboMedia:: getCombo(){
    return combo;
}
