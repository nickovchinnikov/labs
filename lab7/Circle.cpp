#include "Circle.h"
#include <iostream>

Circle::Circle(double radius) : radius(radius) {}

Circle::~Circle() {}

double Circle::getArea() const {
    return 3.14159 * radius * radius;
}

void Circle::display() const {
    std::cout << "Circle";
}
