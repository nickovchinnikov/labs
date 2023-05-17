#include "Shape.cpp"
#include "Circle.cpp"
#include "Square.cpp"
#include "Triangle.cpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<Shape*> shapes;

    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 6.0);

    shapes.push_back(&circle);
    shapes.push_back(&square);
    shapes.push_back(&triangle);

    for (const auto& shape : shapes) {
        shape->printInfo();
        std::cout << std::endl;
    }

    Shape::displayCount();

    return 0;
}
