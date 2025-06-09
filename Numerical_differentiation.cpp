#include<iostream>
#define f(x,y) (x + y)

using namespace std;

int main()
{
    float x0, y0, xn, h, yn, slope, k1, k2, k3, k4;
    int i, n, method;

    cout << "Enter Initial Condition" << endl;
    cout << "x0 = ";
    cin >> x0;
    cout << "y0 = ";
    cin >> y0;
    cout << "Enter calculation point xn = ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Select method:\n1. Euler\n2. Heun\n3. RK4\nChoice: ";
    cin >> method;

    h = (xn - x0) / n;

    cout << "\nx0\ty0\t";
    if (method == 1) cout << "slope\t";
    if (method == 2) cout << "k1\tk2\t";
    if (method == 3) cout << "k1\tk2\tk3\tk4\t";
    cout << "yn\n";
    cout << "--------------------------------------------------------\n";

    for (i = 0; i < n; i++) {
        switch (method) {
            case 1:
                slope = f(x0, y0);
                yn = y0 + h * slope;
                cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
                break;
            case 2:
                k1 = f(x0, y0);
                k2 = f(x0 + h, y0 + h * k1);
                yn = y0 + h * 0.5 * (k1 + k2);
                cout << x0 << "\t" << y0 << "\t" << k1 << "\t" << k2 << "\t" << yn << endl;
                break;
            case 3:
                k1 = f(x0, y0);
                k2 = f(x0 + h / 2, y0 + h / 2 * k1);
                k3 = f(x0 + h / 2, y0 + h / 2 * k2);
                k4 = f(x0 + h, y0 + h * k3);
                yn = y0 + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
                cout << x0 << "\t" << y0 << "\t" << k1 << "\t" << k2 << "\t" << k3 << "\t" << k4 << "\t" << yn << endl;
                break;
            default:
                cout << "Invalid method\n";
                return 1;
        }
        y0 = yn;
        x0 = x0 + h;
    }

    cout << "\nValue of y at x = " << xn << " is " << yn;

    return 0;
}
 
