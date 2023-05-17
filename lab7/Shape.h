#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    static int count;

    Shape();
    virtual ~Shape();

    virtual double getArea() const = 0;
    virtual void display() const = 0;
    virtual void printInfo() const;
    
    static void displayCount();
};

#endif
