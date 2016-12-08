#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stack>
#include <map>
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

class Command
{
    public:
        Command();
        virtual ~Command();

    protected:

    private:
        string cmdText;
        vector<string> sliceVector;
        vector<Media*> mds;
        map<string, Media*> mapName;


        void analysisInput();
        Circle* makeCir(string cir, string name);
        Rectangle* makeRec(string rec, string name);
        Triangle* makeTri(string tri, string name);
        void makeCombo(ComboMediaBuilder* cmb, string content, string name);
};

#endif // COMMAND_H
