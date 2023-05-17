#include "Polynomial.h"

Polynomial::Polynomial(int degree) : degree(degree) {
    coefficients = new double[degree + 1];
}

Polynomial::Polynomial(const Polynomial& other) : degree(other.degree) {
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = other.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial&& other) : degree(other.degree), coefficients(other.coefficients) {
    other.degree = 0;
    other.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        delete[] coefficients;
        degree = other.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial&& other) {
    if (this != &other) {
        delete[] coefficients;
        degree = other.degree;
        coefficients = other.coefficients;
        other.degree = 0;
        other.coefficients = nullptr;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = std::max(degree, other.degree);
    Polynomial result(maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        double a = (i <= degree) ? coefficients[i] : 0.0;
        double b = (i <= other.degree) ? other.coefficients[i] : 0.0;
        result.coefficients[i] = a + b;
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxDegree = std::max(degree, other.degree);
    Polynomial result(maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        double a = (i <= degree) ? coefficients[i] : 0.0;
        double b = (i <= other.degree) ? other.coefficients[i] : 0.0;
        result.coefficients[i] = a - b;
    }

    return result;
}

Polynomial Polynomial::operator*(double scalar) const {
    Polynomial result(degree);

    for (int i = 0; i <= degree; i++) {
        result.coefficients[i] = coefficients[i] * scalar;
    }

    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

Polynomial& Polynomial::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (int i = poly.degree; i >= 0; i--) {
        if (poly.coefficients[i] != 0.0) {
            if (i != poly.degree) {
                if (poly.coefficients[i] > 0.0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            }

            double absCoefficient = std::abs(poly.coefficients[i]);
            if (absCoefficient != 1.0 || i == 0) {
                os << absCoefficient;
            }

            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
        }
    }

    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
    std::cout << "Enter the degree of the polynomial: ";
    is >> poly.degree;

    delete[] poly.coefficients;
    poly.coefficients = new double[poly.degree + 1];

    for (int i = poly.degree; i >= 0; i--) {
        std::cout << "Enter the coefficient of x^" << i << ": ";
        is >> poly.coefficients[i];
    }

    return is;
}
