#include "addCommand.h"

addCommand::addCommand(Media* toAdd, Media* target,map<string, string>* comboContent, string toName, string tarName):toAddMedia(toAdd),targetMedia(target),
    comboContent(comboContent),toMediaName(toName),targetMediaName(tarName)
{
    //ctor
}

addCommand::~addCommand()
{
    //dtor
}

void addCommand::Execute(){
    targetMedia->add(toAddMedia);
    (*comboContent)[targetMediaName] += (toMediaName + " ");
}

void addCommand::Undo(){
    targetMedia->removeMedia(toAddMedia);
    int index = (*comboContent)[targetMediaName].find(toMediaName);
    (*comboContent)[targetMediaName].erase(index-1, toMediaName.length()+1);
}
