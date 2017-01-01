#ifndef DELETEALLCOMMAND_H
#define DELETEALLCOMMAND_H

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

class deleteAllCommand: public Command
{
    public:
        deleteAllCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent);
        virtual ~deleteAllCommand();
        void Execute();
        void Undo();

    protected:

    private:
        vector<string> sliceVector;
        map<string, Media*>* mapName;
        map<string, string>* comboContent;

        vector<Media*> hasMoveMedia;
        vector<string> hasMoveMediaName;

        Media* toDel;
};

#endif // DELETEALLCOMMAND_H
