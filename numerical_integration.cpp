#include <iostream>
#include <cmath>
#include <functional>

double f(double x) {
    return std::sin(x);
}

double trapezoidal(double a, double b, std::function<double(double)> func) {
    return (b - a) * (func(a) + func(b)) / 2.0;
}

double compositeTrapezoidal(double a, double b, int n, std::function<double(double)> func) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        sum += 2.0 * func(a + i * h);
    }
    return (h / 2.0) * sum;
}

double simpson13(double a, double b, std::function<double(double)> func) {
    double h = (b - a) / 2.0;
    return (h / 3.0) * (func(a) + 4.0 * func(a + h) + func(b));
}

double compositeSimpson13(double a, double b, int n, std::function<double(double)> func) {
    if (n % 2 != 0) {
        std::cerr << "Error: n must be even for Composite Simpson's 1/3 Rule." << std::endl;
        return NAN;
    }
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        double coef = (i % 2 == 0) ? 2.0 : 4.0;
        sum += coef * func(a + i * h);
    }
    return (h / 3.0) * sum;
}

double simpson38(double a, double b, std::function<double(double)> func) {
    double h = (b - a) / 3.0;
    return (3.0 * h / 8.0) * (func(a) + 3.0 * func(a + h)
                               + 3.0 * func(a + 2.0 * h) + func(b));
}

double compositeSimpson38(double a, double b, int n, std::function<double(double)> func) {
    if (n % 3 != 0) {
        std::cerr << "Error: n must be a multiple of 3 for Composite Simpson's 3/8 Rule." << std::endl;
        return NAN;
    }
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        double coef = (i % 3 == 0) ? 2.0 : 3.0;
        sum += coef * func(a + i * h);
    }
    return (3.0 * h / 8.0) * sum;
}

double boole(double a, double b, std::function<double(double)> func) {
    double h = (b - a) / 4.0;
    return (2.0 * h / 45.0) * (7.0 * func(a)
                               + 32.0 * func(a + h)
                               + 12.0 * func(a + 2.0 * h)
                               + 32.0 * func(a + 3.0 * h)
                               + 7.0 * func(b));
}

int main() {
    double a = 0.0;
    double b = M_PI;
    int n2 = 10;
    int n3 = 12;

    std::cout << "Trapezoidal Rule: " << trapezoidal(a, b, f) << std::endl;
    std::cout << "Composite Trapezoidal (n=" << n2 << "): " << compositeTrapezoidal(a, b, n2, f) << std::endl;
    std::cout << "Simpson 1/3 Rule: " << simpson13(a, b, f) << std::endl;
    std::cout << "Composite Simpson 1/3 (n=" << n2 << "): " << compositeSimpson13(a, b, n2, f) << std::endl;
    std::cout << "Simpson 3/8 Rule: " << simpson38(a, b, f) << std::endl;
    std::cout << "Composite Simpson 3/8 (n=" << n3 << "): " << compositeSimpson38(a, b, n3, f) << std::endl;
    std::cout << "Boole's Rule: " << boole(a, b, f) << std::endl;

    return 0;
}
