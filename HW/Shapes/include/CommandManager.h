#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <stack>
#include <iostream>
#include "Command.h"

using namespace std;

class CommandManager
{
    public:
        CommandManager();
        virtual ~CommandManager();
        void ExecuteCMD(Command *cmd);
        void RedoCMD();
        void UndoCMD();


    protected:

    private:
        stack<Command*> undocmds;
        stack<Command*> redocmds;

};

#endif // COMMANDMANAGER_H
