#ifndef DEFCOMMAND_H
#define DEFCOMMAND_H

#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

#include "Command.h"
#include "Media.h"
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class defCommand: public Command
{
    public:
        defCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent);
        virtual ~defCommand();
        void Execute();
        void Undo();

    protected:

    private:
        vector<string> sliceVector;
        map<string, Media*>* mapName;
        map<string, string>* comboContent;

        Circle* makeCir(string cir, string name);
        Rectangle* makeRec(string rec, string name);
        Triangle* makeTri(string tri, string name);
        void makeCombo(ComboMediaBuilder* cmb, string content, string name);
};

#endif // DEFCOMMAND_H
