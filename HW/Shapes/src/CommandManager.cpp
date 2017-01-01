#include "CommandManager.h"

CommandManager::CommandManager()
{
    //ctor
}

CommandManager::~CommandManager()
{
    //dtor
}

void CommandManager::ExecuteCMD(Command *cmd){
    cmd->Execute();
    redocmds = stack<Command*>();
    undocmds.push(cmd);
}

void CommandManager::RedoCMD(){
    if (!redocmds.empty()){
        cout << "redo" << endl;
        redocmds.top()->Execute();
        undocmds.push(redocmds.top());
        redocmds.pop();
    }
}

void CommandManager::UndoCMD(){
    if (!undocmds.empty()){
        cout << "undo" << endl;
        undocmds.top() -> Undo();
        redocmds.push(undocmds.top());
        undocmds.pop();
    }
}
