#include "defCommand.h"

defCommand::defCommand(vector<string> sliceVector, map<string, Media*>* mapName, map<string, string>* comboContent):
    sliceVector(sliceVector), mapName(mapName), comboContent(comboContent)
{
    //ctor
}

defCommand::~defCommand()
{
    //dtor
}

void defCommand::Execute(){
    string name = sliceVector[1];
    string content = sliceVector[2];

    if (content[0] == 'C') {
        if (content[1] == 'i') {
            ShapeMediaBuilder smb;
            size_t rightEnd = content.find(")", 7);
            smb.buildShapeMedia(makeCir(content.substr(7,rightEnd-7), name));
            (*mapName)[name]= smb.getMedia();
            cout << content << endl;
        }
    }else if (content[0] == 'R') {
        ShapeMediaBuilder smb;
        size_t rightEnd = content.find(")", 10);
        smb.buildShapeMedia(makeRec(content.substr(10,rightEnd-10), name));
        (*mapName)[name]= smb.getMedia();
        cout << content << endl;
    }else if (content[0] == 'T') {
        ShapeMediaBuilder smb;
        size_t rightEnd = content.find(")", 9);
        smb.buildShapeMedia(makeTri(content.substr(9,rightEnd-9), name));
        (*mapName)[name]= smb.getMedia();
        cout << content << endl;
    }else if (content[0] == 'c' && content[1] == 'o'){
        ComboMediaBuilder cmb;
        makeCombo(&cmb, sliceVector[3], name);
    }
}

void defCommand::Undo(){
    map<string, Media*>::iterator iter;
    map<string, string>::iterator contentIter;
    iter = mapName->find(sliceVector[1]);
    Media* toDel = iter->second;
    for(iter = mapName->begin(); iter != mapName->end(); iter++){
        iter->second->removeMedia(toDel);
    }
    iter = mapName->find(sliceVector[1]);
    mapName->erase(iter);
    for (contentIter= comboContent->begin(); contentIter!=comboContent->end(); contentIter++){
        int index = (*comboContent)[contentIter->first].find(sliceVector[1]);
        if (index!=-1){
            (*comboContent)[contentIter->first].erase(index, sliceVector[1].length());
        }
    }
}

Circle* defCommand::makeCir(string cir, string name){
    stringstream ss(cir);
    string subStr;
    double num[3];
    int i=0;
    while(getline(ss,subStr,',')){
        stringstream(subStr) >> num[i];
        i++;
    }
    Circle* c = new Circle(num[0], num[1], num[2], name);
    return c;
}

Rectangle* defCommand::makeRec(string rec, string name){
    stringstream ss(rec);
    string subStr;
    double num[4];
    int i=0;
    while(getline(ss,subStr,',')){
        stringstream(subStr) >> num[i];
        i++;
    }

    Rectangle* r = new Rectangle(num[0], num[1], num[2], num[3], name);
    return r;
}

Triangle* defCommand::makeTri(string tri, string name){
    stringstream ss(tri);
    string subStr;
    double num[6];
    int i=0;
    while(getline(ss,subStr,',')){
        stringstream(subStr) >> num[i];
        i++;
    }

    Triangle* t = new Triangle(num[0], num[1], num[2], num[3], num[4], num[5], name);

    return t;
}

void defCommand::makeCombo(ComboMediaBuilder* cmb, string content, string name) {
    char *cstr = new char[content.size() + 1];
    strcpy(cstr, content.c_str());
    const char *token = ",";
    char *p;
    p = strtok(cstr, token);
    string temp;
    vector<string> shapes;
    DescriptionVisitor dv;

    map<string, Media*>::iterator iter;

    while (p) {
        shapes.push_back(temp.assign(p));
        p = strtok(NULL, token);
    }
    (*comboContent)[name] = "";
    for (int j = 0; j< shapes.size(); j++) {
        iter = (*mapName).find(shapes[j]);
        cmb->buildComboMedia(iter->second);
        (*comboContent)[name] += (shapes[j] + " ");
    }
    (*mapName)[name]= cmb->getMedia();

    cmb->getMedia()->accept(&dv);
    cout << name << " = " << name << "{"<< (*comboContent)[name];
    cout <<"}" << " = " << dv.getDescription() << endl;
}
