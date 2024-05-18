#include <bits/stdc++.h>
using namespace std;
#define f(x) ((x)*(x)*(x) - (x) - 1)
#define g(x) (pow((1 + (x)), 1.0/3.0))

int main() {
    double x0, x1, e;
    int step = 1, N;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum number of iterations: ";
    cin >> N;
    cout << fixed << setprecision(6);

    do {
        x1 = g(x0);
        step++;
        if (step > N) {
            cout << "Not Convergent" << endl;
            return 1;
        }
        cout << "Iteration number: " << step - 1 << ", x1: " << x1 << ", f(x1): " << f(x1) << endl;
        x0 = x1;
    } while (fabs(f(x1)) > e);
    cout << "Root is: " << x1 << endl;
    return 0;
}
