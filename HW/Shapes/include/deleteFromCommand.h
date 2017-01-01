#ifndef DELETEFROMCOMMAND_H
#define DELETEFROMCOMMAND_H

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

class deleteFromCommand: public Command
{
    public:
        deleteFromCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent);
        virtual ~deleteFromCommand();
        void Execute();
        void Undo();

    protected:

    private:
        vector<string> sliceVector;
        map<string, Media*>* mapName;
        map<string, string>* comboContent;

        Media* toDel;
        Media* target;
};

#endif // DELETEFROMCOMMAND_H
