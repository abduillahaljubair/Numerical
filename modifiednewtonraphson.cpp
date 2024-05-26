#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> a, b;

// Function to evaluate the polynomial at x
double f(double x) {
    double res = a[0];
    for (int i = 1; i < n + 1; i++) {
        res = res * x + a[i];
    }
    return res;
}

// Function to evaluate the derivative of the polynomial at x
double fp(double x) {
    double res = a[0] * n; // Starting with the highest degree term
    for (int i = 1; i < n; i++) {
        res = res * x + (n - i) * a[i];
    }
    return res;
}

// Function to perform synthetic division
vector<double> synthetic(double root) {
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = a[i] + b[i - 1] * root;
    }
    return b;
}

int main() {
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    a.resize(n + 1);
    b.resize(n);

    cout << "Enter the coefficients (highest degree to constant term): ";
    for (int i = 0; i < n + 1; i++) {
        cin >> a[i];
    }

    double tolerance = 0.001;
    double x0 = 1, x1;
    int n1 = n;
    int itr = 0;
    int ct = 0;

    while (n1 > 1) {
        double e;
        do {
            double f1 = f(x0);
            double f2 = fp(x0);
            if (fabs(f2) < 1e-12) {
                cerr << "Derivative too small, Newton-Raphson method fails." << endl;
                return 1;
            }
            x1 = x0 - (f1 / f2);
            e = fabs(x1 - x0);
            x0 = x1;
            itr++;
        } while (e > tolerance);

        ct++;
        cout << "Iteration: " << itr << ", Root " << ct << ": " << x0 << endl;

        a = synthetic(x0);
        a.resize(n); // Update the polynomial coefficients after synthetic division
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
        n--;
        n1 = n;
        x0 = 1; // Reset x0 for the next root finding
    }

    if (n == 1) {
        double finalRoot = -a[1] / a[0];
        ct++;
        itr++;
        cout << "Iteration: " << itr << ", Final root " << ct << ": " << finalRoot << endl;
    }

    return 0;
}
