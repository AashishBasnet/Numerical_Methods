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
        double logY = log(y[i]);  // natural log for e^bx
        sumX += x[i];
        sumY += logY;
        sumXY += x[i]*logY;
        sumX2 += x[i]*x[i];
    }

    double b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double A = (sumY - b*sumX) / n;
    double a = exp(A);

    cout << "Equation: y = " << a << " * e^(" << b << "x)\n";
    return 0;
}
