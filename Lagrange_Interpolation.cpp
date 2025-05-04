#include <iostream>
using namespace std;

int main() {
    int n;
    float x[100], y[100], xp, yp = 0;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter data points (x y):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    cout << "Enter interpolation point (xp): ";
    cin >> xp;

    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }

    cout << "Interpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
