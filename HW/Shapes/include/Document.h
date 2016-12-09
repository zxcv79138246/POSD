#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Document
{
    public:
        Document();
        virtual ~Document();
        string openDocument(const string name){
            if(!canOpenDocument(name)){
                throw string("file is not existed.");
            }
            openFile(name);
            return readFile();
        }

        vector<string> openFullDocument(const string name){
            if(!canOpenDocument(name)){
                throw string("file is not existed.");
            }
            openFile(name);
            return readFullFile();
        }

    protected:
        virtual void openFile(const string name) = 0;
        virtual bool canOpenDocument(const string name) = 0;
        virtual string readFile() = 0;
        virtual vector<string> readFullFile() = 0;

    private:
};

#endif // DOCUMENT_H
