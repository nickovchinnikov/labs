#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    Polynomial(int degree = 0);
    Polynomial(const Polynomial& other);
    Polynomial(Polynomial&& other);
    ~Polynomial();

    Polynomial& operator=(const Polynomial& other);
    Polynomial& operator=(Polynomial&& other);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(double scalar) const;

    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(double scalar);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
    friend std::istream& operator>>(std::istream& is, Polynomial& poly);
};

#endif
