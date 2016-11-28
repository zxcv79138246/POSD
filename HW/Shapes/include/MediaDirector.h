#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H

#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>
#include "MediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"


using namespace std;

class MediaDirector
{
    public:
        MediaDirector();
        virtual ~MediaDirector();
        void setMediaBuilder(stack<MediaBuilder *> *mbs);
		void concrete(string content);
		Rectangle* makeRec(string rec);
		Circle* makeCir(string cir);
		Triangle* makeTri(string tri);
		stack<MediaBuilder *> getMb();

    protected:

    private:
        stack<MediaBuilder *> *mb;
};

#endif // MEDIADIRECTOR_H
