#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n], sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    cout << "Enter x and y values:\n";
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        double logX = log10(x[i]);
        double logY = log10(y[i]);
        sumX += logX;
        sumY += logY;
        sumXY += logX*logY;
        sumX2 += logX*logX;
    }

    double b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double A = (sumY - b*sumX) / n;
    double a = pow(10, A);

    cout << "Equation: y = " << a << " * x^" << b << "\n";
    return 0;
}
