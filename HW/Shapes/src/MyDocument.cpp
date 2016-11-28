#include "MyDocument.h"

MyDocument::MyDocument()
{
    //ctor
}

MyDocument::~MyDocument()
{
    //dtor
}

void MyDocument::openFile(const string name){
    fp.open(name, ios::in);
}

bool MyDocument::canOpenDocument(const string name){
    fstream openFp;
    openFp.open(name, ios::in);

    //如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!openFp){
        return false;
    }

    return true;
}

string MyDocument::readFile(){
    string line;
    getline(fp, line);
    return line;
}

