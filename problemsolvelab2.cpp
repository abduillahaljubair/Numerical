#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1416;
const double V = 800.0;
const double R = 10.0;

// Function f(h)
double f(double h) {
    return (PI * h * h * (3 * R - h) / 3.0) - V;
}

// Derivative of f(h)
double f_prime(double h) {
    return (2 * PI * h * (3 * R - h) / 3.0) - (PI * h * h / 3.0);
}

int main() {
    double x0 = 16.0;  // Initial guess
    double x1, error;
    int itr = 0;

    cout << fixed << setprecision(10);

    do {
        x1 = x0 - f(x0) / f_prime(x0);
        error = fabs((x1 - x0) / x1);
        itr++;
        cout << "Iteration " << itr << ": f(h1)= " << f(x1) << ", f_prime(h)= " << f_prime(x1) << ", root= " << x1 << ", error= " << error << endl;
        x0 = x1;
    } while (fabs(error) > 0.000001);

    cout << itr << " iterations, root = " << x1 << endl;

    return 0;
}
