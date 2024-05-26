#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100];

double f(double x) {
    double res = arr[n];
    for (int i = n - 1; i >= 0; i--) {
        res = res * x + arr[i];
    }
    return res;
}

int main() {
    double error = 0.001;
    cout << "Enter maximum power: ";
    cin >> n;
    cout << "Enter the coefficients: " << endl;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    double a, b;
    cout << "Enter lower and upper value: ";
    cin >> a >> b;
    double dx = 0.5;
    double x1, x2;

    cout << "\tx0\t\tx1\t\tx2\t\tf0\t\tf1\t\tf2\t\terror\t" << endl;

    while (a < b) {
        x1 = a;
        x2 = x1 + dx;
        double f1 = f(x1);
        double f2 = f(x2);

        if (f1 * f2 < 0) {
            while (true) {
                double x0 = (x1 + x2) / 2.0;
                double f0 = f(x0);

                if (f1 * f0 < 0) {
                    x2 = x0;
                    f2 = f0;
                } else {
                    x1 = x0;
                    f1 = f0;
                }

                double err = fabs((x2 - x1) / x2);

                printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x0, x1, x2, f0, f1, f2, err);

                if (err <= error)
                {
                    double root = (x1 + x2) / 2.0;
                    cout << endl;
                    cout << "Between " << x1 << " and " << x2 << " there is a root " << root << endl;
                    break;
                }
            }
        }
        if (x2 < b) {
            a = x2;
        } else {
            break;
        }
    }

    return 0;
}
