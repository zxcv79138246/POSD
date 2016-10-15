#ifndef MEDIA_H
#define MEDIA_H

class AreaVisitor;
class Media
{
    public:
        Media();
        virtual ~Media();
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void accept(AreaVisitor* areaVisitor) = 0;

    protected:

    private:
};

#endif // MEDIA_H
