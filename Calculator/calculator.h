#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <string>

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);     // throws on divide-by-zero
    double power(double base, double exp);
    double squareRoot(double a);           // throws on negative input

    // Parses and evaluates a simple "a op b" expression string
    double evaluate(const std::string& expression);
};

#endif
