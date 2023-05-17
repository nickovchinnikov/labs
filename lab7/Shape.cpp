#include "Shape.h"
#include <iostream>

int Shape::count = 0;

Shape::Shape() {
    count++;
}

Shape::~Shape() {
    count--;
}

void Shape::printInfo() const {
    std::cout << "Shape: ";
    display();
    std::cout << "Area: " << getArea() << std::endl;
}

void Shape::displayCount() {
    std::cout << "Number of shapes: " << count << std::endl;
}
