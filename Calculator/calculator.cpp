#include "calculator.h"
#include <cmath>
#include <sstream>

double Calculator::add(double a, double b)      { return a + b; }
double Calculator::subtract(double a, double b) { return a - b; }
double Calculator::multiply(double a, double b) { return a * b; }

double Calculator::divide(double a, double b) {
    if (b == 0) throw std::invalid_argument("Division by zero");
    return a / b;
}

double Calculator::power(double base, double exp) {
    return std::pow(base, exp);
}

double Calculator::squareRoot(double a) {
    if (a < 0) throw std::invalid_argument("Cannot take sqrt of negative number");
    return std::sqrt(a);
}

double Calculator::evaluate(const std::string& expr) {
    std::istringstream iss(expr);
    double a, b;
    char op;

    if (!(iss >> a >> op >> b))
        throw std::invalid_argument("Invalid expression format. Use: number op number");

    switch (op) {
    case '+': return add(a, b);
    case '-': return subtract(a, b);
    case '*': return multiply(a, b);
    case '/': return divide(a, b);
    case '^': return power(a, b);
    default:  throw std::invalid_argument("Unknown operator: " + std::string(1, op));
    }
}
