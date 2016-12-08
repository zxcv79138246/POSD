#include "Command.h"

Command::Command()
{
    while(getline(cin,cmdText)) {
        analysisInput();
        sliceVector.clear();
    }
}

Command::~Command()
{
    //dtor
}

void Command:: analysisInput() {
    char *cstr = new char[cmdText.size() + 1];;
    strcpy(cstr, cmdText.c_str());
    const char *token = " =.?{}\"";
    char *p;
    p = strtok(cstr, token);
    string temp;

    while (p) {
        sliceVector.push_back(temp.assign(p));
        p = strtok(NULL, token);
    }
    //
    for (int i ; i<sliceVector.size(); i++ ){
        cout << sliceVector[i] << endl;
    }
    //
    DescriptionVisitor descriptionVisitor;
    if (sliceVector[0] == "def"){
        string name = sliceVector[1];
        string content = sliceVector[2];
        DescriptionVisitor descriptionVisitor;
        if (content[0] == 'C') {
            if (content[1] == 'i') {
                ShapeMediaBuilder smb;
                size_t rightEnd = content.find(")", 7);
                smb.buildShapeMedia(makeCir(content.substr(7,rightEnd-7), name));
                mds.push_back(smb.getMedia());
                mapName[name]= smb.getMedia();
                cout << content << endl;
            }
        }else if (content[0] == 'R') {
            ShapeMediaBuilder smb;
            size_t rightEnd = content.find(")", 10);
            smb.buildShapeMedia(makeRec(content.substr(10,rightEnd-7), name));
            mds.push_back(smb.getMedia());
            mapName[name]= smb.getMedia();
            cout << content << endl;
        }else if (content[0] == 'T') {
            ShapeMediaBuilder smb;
            size_t rightEnd = content.find(")", 9);
            smb.buildShapeMedia(makeTri(content.substr(9,rightEnd-7), name));
            mds.push_back(smb.getMedia());
            mapName[name]= smb.getMedia();
            cout << content << endl;
        }else if (content[0] == 'c' && content[1] == 'o'){
            cout << "combo!!" << endl;
            ComboMediaBuilder cmb;
            makeCombo(&cmb, sliceVector[3], name);
        }
    }else if (sliceVector[0] == "add"){
        cout << "add!!" <<endl;
        DescriptionVisitor dv;
        map<string, Media*>::iterator iter;
        iter = mapName.find(sliceVector[1]);
        Media* toAdd = iter->second;
        iter = mapName.find(sliceVector[3]);
        Media* target = iter->second;
        target->add(toAdd);
        target->accept(&dv);
        cout << sliceVector[3] << " = " << sliceVector[3] << "{" << sliceVector[1] <<" }" << " = " << dv.getDescription() << endl;
    }else if (sliceVector[0] == "show") {
        map<string, Media*>::iterator iter;
        for(iter = mapName.begin(); iter != mapName.end(); iter++){
            cout << iter->first<<endl;
        }
    }else if (sliceVector[0] == "delete"){
        DescriptionVisitor dv;
        map<string, Media*>::iterator iter;
        iter = mapName.find(sliceVector[1]);
        Media* toDel = iter->second;
        if (sliceVector[2] == "from"){
            iter = mapName.find(sliceVector[3]);
            Media* target = iter->second;
            target->removeMedia(toDel);
        }else {
            for(iter = mapName.begin(); iter != mapName.end(); iter++){
                iter->second->removeMedia(toDel);
            }
            iter = mapName.find(sliceVector[1]);
            mapName.erase(iter);
        }
    }


    else if (sliceVector[0] != "def" && sliceVector[1] == "area"){
        cout << "getArea!!"<<endl;
        map<string, Media*>::iterator iter;
        iter = mapName.find(sliceVector[0]);
        cout << iter->second->area()<<endl;
    }else if (sliceVector[0] != "def" && sliceVector[1] == "perimeter"){
        cout << "getPerimeter!!"<<endl;
        map<string, Media*>::iterator iter;
        iter = mapName.find(sliceVector[0]);
        cout << iter->second->perimeter()<<endl;
    }
}

Circle* Command::makeCir(string cir, string name){
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

Rectangle* Command::makeRec(string rec, string name){
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

Triangle* Command::makeTri(string tri, string name){
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

void Command::makeCombo(ComboMediaBuilder* cmb, string content, string name) {
    char *cstr = new char[content.size() + 1];
    strcpy(cstr, content.c_str());
    const char *token = ",";
    char *p;
    p = strtok(cstr, token);
    string temp;
    vector<string> shapes;
    map<string, Media*>::iterator iter;
    while (p) {
        shapes.push_back(temp.assign(p));
        p = strtok(NULL, token);
    }
    for (int j = 0; j< shapes.size(); j++) {
        iter = mapName.find(shapes[j]);
        cmb->buildComboMedia(iter->second);
    }
    mapName[name]= cmb->getMedia();
}
