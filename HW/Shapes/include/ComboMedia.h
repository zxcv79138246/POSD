#ifndef COMBOMEDIA_H
#define COMBOMEDIA_H

#include "Media.h"
#include "AreaVisitor.h"

using namespace std;

class AreaVisitor;
class ComboMedia : public Media
{
    public:
        ComboMedia();
        virtual ~ComboMedia();
        void add(Media* media);
        double area();
        double perimeter();
        void accept(AreaVisitor* areaVisitor);
        vector<Media*> getCombo();

    protected:

    private:
        string name;
        vector<Media*> combo;
};

#endif // COMBOMEDIA_H
