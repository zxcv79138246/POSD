#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>

using namespace std;

class AreaVisitor;
class PerimeterVisitor;

class Media
{
    public:
        Media();
        virtual ~Media();
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void accept(AreaVisitor& areaVisitor) = 0;
        virtual void accept(PerimeterVisitor& perimeterVisitor) = 0;

    protected:

    private:
};

#endif // MEDIA_H
