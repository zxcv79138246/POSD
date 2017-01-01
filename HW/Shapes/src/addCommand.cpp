#include "addCommand.h"

addCommand::addCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent):
    sliceVector(sliceVector), mapName(mapName), comboContent(comboContent)
{
    //ctor
}

addCommand::~addCommand()
{
    //dtor
}

void addCommand::Execute(){
    map<string, Media*>::iterator iter;
    iter = mapName->find(sliceVector[1]);
    toAdd = iter->second;
    iter = mapName->find(sliceVector[3]);
    target = iter->second;

    target->add(toAdd);
    (*comboContent)[sliceVector[3]] += (sliceVector[1] + " ");
}

void addCommand::Undo(){
    target->removeMedia(toAdd);
    int index = (*comboContent)[sliceVector[3]].find(sliceVector[1]);
    (*comboContent)[sliceVector[3]].erase(index-1, sliceVector[1].length()+1);
}
