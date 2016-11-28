#ifndef MYDOCUMENT_H
#define MYDOCUMENT_H

#include "Document.h"

class MyDocument: public Document
{
    public:
        MyDocument();
        virtual ~MyDocument();

    protected:
        void openFile(const string name);
        bool canOpenDocument(const string name);
        string readFile();

    private:
        fstream fp;
};

#endif // MYDOCUMENT_H
