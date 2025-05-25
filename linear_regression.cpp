#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n], sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    cout << "Enter x and y values:\n";
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumX2 += x[i]*x[i];
    }

    double b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double a = (sumY - b*sumX) / n;

    cout << "Equation: y = " << a << " + " << b << "x\n";
    return 0;
}
