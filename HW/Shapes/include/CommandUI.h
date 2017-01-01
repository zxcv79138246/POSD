#ifndef CommandUI_H
#define CommandUI_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stack>
#include <map>
#include <fstream>
#include <cstdio>
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "MyDocument.h"
#include "MediaDirector.h"

#include "CommandManager.h"
#include "addCommand.h"
#include "defCommand.h"
#include "deleteFromCommand.h"
#include "deleteAllCommand.h"


using namespace std;

class CommandUI
{
    public:
        CommandUI();
        virtual ~CommandUI();

    protected:

    private:
        vector<string> sliceVector;
        vector<Media*> mds;
        map<string, Media*> mapName;
        map<string, string> comboContent;


        void analysisInput(string cmdText);
        Circle* makeCir(string cir, string name);
        Rectangle* makeRec(string rec, string name);
        Triangle* makeTri(string tri, string name);
        void makeCombo(ComboMediaBuilder* cmb, string content, string name);
        CommandManager* cmdMng;
};

#endif // CommandUI_H
