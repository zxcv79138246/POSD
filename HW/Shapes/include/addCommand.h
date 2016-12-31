#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <map>

#include "Command.h"
#include "Media.h"

class addCommand: public Command
{
    public:
        addCommand(Media* toAdd, Media* target, map<string, string>* comboContent, string toName, string tarName);
        virtual ~addCommand();
        void Execute();
        void Undo();

    protected:

    private:
        Media* toAddMedia;
        Media* targetMedia;
        map<string, string>* comboContent;
        string toMediaName;
        string targetMediaName;
};

#endif // ADDCOMMAND_H
