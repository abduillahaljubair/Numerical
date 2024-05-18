#include <bits/stdc++.h>
using namespace std;

vector<float> a; // Using float for potential floating-point coefficients

// Function to evaluate polynomial using Horner's method
float horners(float x) {
    float res = a[0];
    for (int i = 1; i < a.size(); i++) {
        res =res*x+a[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    float x;
    cin >> x;
    float result = horners(x);
    cout << result << endl;
    return 0;
}
