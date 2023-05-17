#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side;

public:
    Square(double side);
    ~Square();

    double getArea() const override;
    void display() const override;
};

#endif
