#include "deleteAllCommand.h"

deleteAllCommand::deleteAllCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent):
    sliceVector(sliceVector), mapName(mapName), comboContent(comboContent)
{
    //ctor
}

deleteAllCommand::~deleteAllCommand()
{
    //dtor
}

void deleteAllCommand::Execute(){
    map<string, Media*>::iterator iter;
    map<string, string>::iterator contentIter;
    iter = mapName->find(sliceVector[1]);
    toDel = iter->second;
    for(iter = mapName->begin(); iter != mapName->end(); iter++){
        iter->second->removeMedia(toDel);
        hasMoveMedia.push_back(iter->second);
        hasMoveMediaName.push_back(iter->first);
    }
    iter = mapName->find(sliceVector[1]);
    mapName->erase(iter);
    for (contentIter=comboContent->begin(); contentIter!=comboContent->end(); contentIter++){
        int index = (*comboContent)[contentIter->first].find(sliceVector[1]);
        if (index!=-1){
            (*comboContent)[contentIter->first].erase(index, sliceVector[1].length());
        }
    }
}

void deleteAllCommand::Undo(){
    (*mapName)[sliceVector[1]] = toDel;
    for (int i=0; i < hasMoveMedia.size(); i++) {
        hasMoveMedia[i]->add(toDel);
        (*comboContent)[hasMoveMediaName[i]] += (sliceVector[1] + " ");
    }
}
