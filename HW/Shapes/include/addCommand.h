#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <map>

#include "Command.h"
#include "Media.h"

class addCommand: public Command
{
    public:
        addCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent);
        virtual ~addCommand();
        void Execute();
        void Undo();

    protected:

    private:
        vector<string> sliceVector;
        map<string, Media*>* mapName;
        map<string, string>* comboContent;

        Media* toAdd;
        Media* target;
};

#endif // ADDCOMMAND_H
