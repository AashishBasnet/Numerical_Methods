#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "\n\n ----------------- BISECTION METHOD ----------------------" << endl << endl;
    int n, iter = 0, max_iter = 100;
    float x1, x2, x0, f1, f2, f0, e;
    float a[100];

    cout << "Enter the degree of the equation: ";
    cin >> n;
    
    cout << "Enter initial guesses: ";
    cin >> x1 >> x2;

    cout << "Enter stopping condition (epsilon): ";
    cin >> e;

    for (int i = 0; i <= n; i++) {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    f1 = f2 = 0;
    for (int i = 0; i <= n; i++) {
        f1 += a[i] * pow(x1, i);
        f2 += a[i] * pow(x2, i);
    }

    if (f1 * f2 > 0) {
        cout << "No root found in the given interval. Choose different guesses." << endl;
        return 0;
    }

    do {
        x0 = (x1 + x2) / 2.0; 

        f0 = 0;
        for (int i = 0; i <= n; i++) {
            f0 += a[i] * pow(x0, i);
        }

        cout << "Iteration " << iter + 1 << ": x0 = " << x0 << ", f(x0) = " << f0 << endl;

        if (fabs(f0) < e) {
            cout << "Root found: " << x0 << endl;
            break;
        }

        if (f0 * f1 < 0) {
            x2 = x0;
            f2 = f0;
        } else {
            x1 = x0;
            f1 = f0;
        }

        iter++;
    } while (iter < max_iter);

    if (iter == max_iter) {
        cout << "Maximum iterations reached. Approximate root: " << x0 << endl;
    }

    return 0;
}
