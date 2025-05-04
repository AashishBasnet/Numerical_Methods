#include <iostream>
#include <iomanip>
#include <cmath>

#define SIZE 10

using namespace std;

int main() {
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float temp, lambda_new, lambda_old = 1, error;
    int n, step = 1;

    cout << setprecision(6) << fixed;

    cout << "Enter Order of Matrix: ";
    cin >> n;

    cout << "Enter Tolerable Error: ";
    cin >> error;

    cout << "Enter Coefficients of Matrix:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }

    cout << "Enter Initial Guess Vector:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    while (true) {
        for (int i = 1; i <= n; i++) {
            temp = 0;
            for (int j = 1; j <= n; j++)
                temp += a[i][j] * x[j];
            x_new[i] = temp;
        }

        for (int i = 1; i <= n; i++)
            x[i] = x_new[i];

        lambda_new = fabs(x[1]);
        for (int i = 2; i <= n; i++)
            if (fabs(x[i]) > lambda_new)
                lambda_new = fabs(x[i]);

        for (int i = 1; i <= n; i++)
            x[i] /= lambda_new;

        cout << "\nSTEP-" << step++ << "\n";
        cout << "Eigen Value = " << lambda_new << "\n";
        cout << "Eigen Vector: [ ";
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
        cout << "]\n";

        if (fabs(lambda_new - lambda_old) <= error)
            break;

        lambda_old = lambda_new;
    }

    return 0;
}
