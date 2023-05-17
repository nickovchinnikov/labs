#include "Square.h"
#include <iostream>

Square::Square(double side) : side(side) {}

Square::~Square() {}

double Square::getArea() const {
    return side * side;
}

void Square::display() const {
    std::cout << "Square";
}
