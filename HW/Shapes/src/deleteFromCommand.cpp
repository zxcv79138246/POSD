#include "deleteFromCommand.h"

deleteFromCommand::deleteFromCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent):
    sliceVector(sliceVector), mapName(mapName), comboContent(comboContent)
{
    //ctor
}

deleteFromCommand::~deleteFromCommand()
{
    //dtor
}

void deleteFromCommand::Execute(){
    map<string, Media*>::iterator iter;
    map<string, string>::iterator contentIter;
    iter = mapName->find(sliceVector[1]);
    toDel = iter->second;
    iter = mapName->find(sliceVector[3]);
    target = iter->second;
    target->removeMedia(toDel);
    int index = (*comboContent)[sliceVector[3]].find(sliceVector[1]);
    (*comboContent)[sliceVector[3]].erase(index, sliceVector[1].length()+1);
}

void deleteFromCommand::Undo(){
    target->add(toDel);
    (*comboContent)[sliceVector[3]] += (sliceVector[1] + " ");
}
