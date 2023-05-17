#include <iostream>
#include "Polynomial.cpp"

int main() {
    // Create a polynomial using the default constructor
    Polynomial poly1;

    // Input polynomial coefficients from the user
    std::cout << "Enter polynomial coefficients:\n";
    std::cin >> poly1;

    // Display the polynomial
    std::cout << "Polynomial 1: " << poly1 << std::endl;

    // Create a second polynomial using the copy constructor
    Polynomial poly2(poly1);

    // Display the second polynomial
    std::cout << "Polynomial 2: " << poly2 << std::endl;

    // Add the polynomials
    Polynomial sum = poly1 + poly2;

    // Display the sum
    std::cout << "Sum: " << sum << std::endl;

    // Multiply the first polynomial by a scalar
    double scalar = 2.5;
    Polynomial scaled = poly1 * scalar;

    // Display the scaled polynomial
    std::cout << "Scaled polynomial: " << scaled << std::endl;

    // Subtract the scaled polynomial from the sum
    sum -= scaled;

    // Display the updated sum
    std::cout << "Updated sum: " << sum << std::endl;

    return 0;
}
