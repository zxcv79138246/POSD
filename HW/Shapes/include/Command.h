#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

using namespace std;

class Command
{
    public:
        Command();
        virtual ~Command();
        virtual void Execute() = 0;
        virtual void Undo() = 0;

    protected:

    private:
};

#endif // COMMAND_H
