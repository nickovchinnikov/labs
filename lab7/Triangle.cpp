#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double base, double height) : base(base), height(height) {}

Triangle::~Triangle() {}

double Triangle::getArea() const {
    return 0.5 * base * height;
}

void Triangle::display() const {
    std::cout << "Triangle";
}
