#include <iostream>
#include <cmath>

double f(double x) {
    return std::sin(x);
}

double trapezoidal(double a, double b) {
    return (b - a) * (f(a) + f(b)) / 2.0;
}

double compositeTrapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        sum += 2.0 * f(a + i * h);
    }
    return (h / 2.0) * sum;
}

double simpson13(double a, double b) {
    double h = (b - a) / 2.0;
    return (h / 3.0) * (f(a) + 4.0 * f(a + h) + f(b));
}

double compositeSimpson13(double a, double b, int n) {
    if (n % 2 != 0) {
        std::cerr << "Error: n must be even for Composite Simpson's 1/3 Rule." << std::endl;
        return NAN;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double coef = (i % 2 == 0) ? 2.0 : 4.0;
        sum += coef * f(a + i * h);
    }
    return (h / 3.0) * sum;
}

double simpson38(double a, double b) {
    double h = (b - a) / 3.0;
    return (3.0 * h / 8.0) * (f(a) + 3.0 * f(a + h)
                               + 3.0 * f(a + 2.0 * h) + f(b));
}

double compositeSimpson38(double a, double b, int n) {
    if (n % 3 != 0) {
        std::cerr << "Error: n must be a multiple of 3 for Composite Simpson's 3/8 Rule." << std::endl;
        return NAN;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double coef = (i % 3 == 0) ? 2.0 : 3.0;
        sum += coef * f(a + i * h);
    }
    return (3.0 * h / 8.0) * sum;
}

double boole(double a, double b) {
    double h = (b - a) / 4.0;
    return (2.0 * h / 45.0) * (7.0 * f(a)
                               + 32.0 * f(a + h)
                               + 12.0 * f(a + 2.0 * h)
                               + 32.0 * f(a + 3.0 * h)
                               + 7.0 * f(b));
}

int main() {
    double a = 0.0;
    double b = M_PI;
    int n2 = 10;
    int n3 = 12;

    std::cout << "Trapezoidal Rule: " << trapezoidal(a, b) << std::endl;
    std::cout << "Composite Trapezoidal (n=" << n2 << "): " << compositeTrapezoidal(a, b, n2) << std::endl;
    std::cout << "Simpson 1/3 Rule: " << simpson13(a, b) << std::endl;
    std::cout << "Composite Simpson 1/3 (n=" << n2 << "): " << compositeSimpson13(a, b, n2) << std::endl;
    std::cout << "Simpson 3/8 Rule: " << simpson38(a, b) << std::endl;
    std::cout << "Composite Simpson 3/8 (n=" << n3 << "): " << compositeSimpson38(a, b, n3) << std::endl;
    std::cout << "Boole's Rule: " << boole(a, b) << std::endl;

    return 0;
}
