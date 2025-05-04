#include <iostream>

using namespace std;

int main() {
    float x0, y0, x1, y1, xp, yp;

    cout << "Enter coordinates of the first point:\n";
    cout << "  x0 = ";
    cin >> x0;
    cout << "  y0 = ";
    cin >> y0;

    cout << "Enter coordinates of the second point:\n";
    cout << "  x1 = ";
    cin >> x1;
    cout << "  y1 = ";
    cin >> y1;

    cout << "Enter x-value to interpolate (xp): ";
    cin >> xp;

    yp = y0 + ((y1 - y0) / (x1 - x0)) * (xp - x0);

    cout << "Interpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
