#include "Command.h"

Command::Command()
{
    string cmdText;
    while(getline(cin,cmdText)) {
        if (cmdText.size()>1){
            analysisInput(cmdText);
            sliceVector.clear();
        }
        cmdText = "";
    }
}

Command::~Command()
{
    //dtor
}

void Command:: analysisInput(string cmdText) {
    sliceVector.clear();
    char *cstr = new char[cmdText.size() + 1];;
    strcpy(cstr, cmdText.c_str());
    const char *token = " =?{}\"";
    char *p;
    p = strtok(cstr, token);
    string temp;
    while (p) {
        sliceVector.push_back(temp.assign(p));
        p = strtok(NULL, token);
    }
    //------------------------
//    for (int i=0; i<sliceVector.size(); i++ ){
//        cout << sliceVector[i] << endl;
//    }
    //----------------------
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
            ComboMediaBuilder cmb;
            makeCombo(&cmb, sliceVector[3], name);
        }
    }else if (sliceVector[0] == "add"){
        DescriptionVisitor dv;
        map<string, Media*>::iterator iter;
        iter = mapName.find(sliceVector[1]);
        Media* toAdd = iter->second;
        iter = mapName.find(sliceVector[3]);
        Media* target = iter->second;
        target->add(toAdd);
        target->accept(&dv);
        comboContent[sliceVector[3]] += (sliceVector[1] + " ");

        cout << sliceVector[3] << " = " << sliceVector[3] << "{"<< comboContent[sliceVector[3]];
        cout <<"}" << " = " << dv.getDescription() << endl;
    }else if (sliceVector[0] == "show") {
        map<string, Media*>::iterator iter;
        for(iter = mapName.begin(); iter != mapName.end(); iter++){
            cout << iter->first<<endl;
        }
    }else if (sliceVector[0] == "delete"){
        DescriptionVisitor dv;
        map<string, Media*>::iterator iter;
        map<string, string>::iterator contentIter;
        iter = mapName.find(sliceVector[1]);
        if (iter != mapName.end()){
            Media* toDel = iter->second;
            if (sliceVector[2] == "from" && sliceVector.size()>2){
                iter = mapName.find(sliceVector[3]);
                Media* target = iter->second;
                target->removeMedia(toDel);
                int index = comboContent[sliceVector[3]].find(sliceVector[1]);
                comboContent[sliceVector[3]].erase(index, sliceVector[1].length());
            }else {
                for(iter = mapName.begin(); iter != mapName.end(); iter++){
                    iter->second->removeMedia(toDel);
                }
                iter = mapName.find(sliceVector[1]);
                mapName.erase(iter);
                for (contentIter=comboContent.begin(); contentIter!=comboContent.end(); contentIter++){
                    int index = comboContent[contentIter->first].find(sliceVector[1]);
                    if (index!=-1){
                        comboContent[contentIter->first].erase(index, sliceVector[1].length());
                    }
                }
            }
        }

    }else if (sliceVector[0] == "save"){
        fstream fp;
        map<string, Media*>::iterator iter;
        DescriptionVisitor dv;
        fp.open(sliceVector[3], ios::out);
        iter = mapName.find(sliceVector[1]);
        Media* target = iter->second;
        target->accept(&dv);
        string desc = dv.getDescription();
        fp <<  dv.getDescription() << endl;
        if (desc[0]=='c' && desc[1]=='o'){
            fp << sliceVector[1] << "{"<< comboContent[sliceVector[1]] <<"}";
        }else {
            fp << sliceVector[1];
        }
        fp.close();
        cout << sliceVector[1] << " saved to " << sliceVector[3] <<endl;

    }else if (sliceVector[0] == "load"){
        cout << "loading " << sliceVector[1] << " ..."<<endl;
        Document* doc = new MyDocument();
        MediaDirector* md = new MediaDirector();
        vector<string> lines;
        try{
            lines = doc->openFullDocument(sliceVector[1]);
        }catch(string s) {
            cout << s << endl;
        }
        stack<MediaBuilder *> mbs;
        md->setMediaBuilder(&mbs);
        md->concrete(lines[0]);

        vector<string> lineVector1;
        char *cstr4 = new char[lines[1].size() + 1];
        strcpy(cstr4, lines[1].c_str());
        const char *token4 = " {}";
        char *p4;
        p4 = strtok(cstr4, token4);
        string temp4;
        while (p4) {
            lineVector1.push_back(temp4.assign(p4));
            p4 = strtok(NULL, token4);
        }

        vector<string> lineVector0;
        char *cstr3 = new char[lines[0].size() + 1];
        strcpy(cstr3, lines[0].c_str());
        const char *token3 = "()";
        char *p3;
        p3 = strtok(cstr3, token3);
        string temp3;
        while (p3) {
            lineVector0.push_back(temp3.assign(p3));
            p3 = strtok(NULL, token3);
        }
        //lineVector0
        for (int i=1 ; i<lineVector0.size(); i++ ){
            if ((lineVector0[i] == "c" ||  lineVector0[i] == " c") && lineVector0[i]!="co"){
                string attr = lineVector0[i+1];
                for (int j=0; j<2; j++){
                    attr.replace(attr.find(" "), 1, ",");
                }
                analysisInput("def "+lineVector1[((i+1)/2)] + " = Circle("+ attr + ")");
                comboContent[lineVector1[0]] += lineVector1[((i+1)/2)] + " ";
            }else if (lineVector0[i] == "r" ||  lineVector0[i] == " r")  {
                string attr = lineVector0[i+1];
                for (int j=0; j<3; j++){
                    attr.replace(attr.find(" "), 1, ",");
                }
                analysisInput("def "+lineVector1[((i+1)/2)] + " = Rectangle("+ attr + ")");
                comboContent[lineVector1[0]] += lineVector1[((i+1)/2)] + " ";
            }else if (lineVector0[i] == "t" ||  lineVector0[i] == " t") {
                string attr = lineVector0[i+1];
                for (int j=0; j<5; j++){
                    attr.replace(attr.find(" "), 1, ",");
                }
                analysisInput("def "+lineVector1[((i+1)/2)] + " = Triangle("+ attr + ")");
                comboContent[lineVector1[0]] += lineVector1[((i+1)/2)] + " ";
            }

        }

        mapName[lineVector1[0]] = mbs.top()->getMedia();
        DescriptionVisitor dv;
        mbs.top()->getMedia()->accept(&dv);
        cout << lineVector1[0] << " = {" << lineVector1[1] << "} = " << dv.getDescription() <<endl;

    }else {
        if (sliceVector.size()>0) {
            char *cstr2 = new char[cmdText.size() + 1];;
            strcpy(cstr2, cmdText.c_str());
            const char *token2 = ".?";
            char *p2;
            p2 = strtok(cstr2, token2);
            string temp2;
            vector<string> sliceVector2;

            while (p2) {
                sliceVector2.push_back(temp2.assign(p2));
                p2 = strtok(NULL, token2);
            }

            if (sliceVector2[1] == "area"){
                map<string, Media*>::iterator iter;
                iter = mapName.find(sliceVector2[0]);
                if (iter != mapName.end()){
                    cout << iter->second->area()<<endl;
                }else {
                    cout << "not found " << sliceVector2[0] <<endl;
                }
            }else if (sliceVector2[1] == "perimeter"){
                map<string, Media*>::iterator iter;
                iter = mapName.find(sliceVector2[0]);
                if (iter != mapName.end()){
                    cout << iter->second->perimeter()<<endl;
                }else {
                    cout << "not found " << sliceVector2[0] <<endl;
                }
            }
        }
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
    DescriptionVisitor dv;

    map<string, Media*>::iterator iter;

    while (p) {
        shapes.push_back(temp.assign(p));
        p = strtok(NULL, token);
    }
    comboContent[name] = "";
    for (int j = 0; j< shapes.size(); j++) {
        iter = mapName.find(shapes[j]);
        cmb->buildComboMedia(iter->second);
        comboContent[name] += (shapes[j] + " ");
    }
    mapName[name]= cmb->getMedia();

    cmb->getMedia()->accept(&dv);
    cout << name << " = " << name << "{"<< comboContent[name];
    cout <<"}" << " = " << dv.getDescription() << endl;
}
