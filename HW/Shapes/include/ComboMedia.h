#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H

#include "Media.h"
#include <iostream>

class AreaVisitor;
class PerimeterVisitor;
class DescriptionVisitor;
class ComboMedia : public Media
{
    public:
        ComboMedia();
        virtual ~ComboMedia();
        void add(Media* media);
        double area();
        double perimeter();
        void accept(AreaVisitor& areaVisitor);
        void accept(PerimeterVisitor& perimeterVisitor);
        void accept(DescriptionVisitor* descriptionVisitor);
        void removeMedia(Media* m);
        vector<Media*> getCombo();
        string name;


    protected:

    private:
        vector<Media*> combo;

};

#endif // COMBOMEDIA_H
