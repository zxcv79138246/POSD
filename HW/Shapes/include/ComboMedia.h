#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H

#include "Media.h"

class AreaVisitor;
class PerimeterVisitor;
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

    protected:

    private:
        string name;
        vector<Media*> combo;
};

#endif // COMBOMEDIA_H
