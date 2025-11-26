#include <iostream>
using namespace std;

// 1. Iterative O(N)
int powerIterative(int a, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}

// 2. Divide & Conquer O(N)
double powerDivideON(double x, int n) {
    if (n == 0) return 1;
    return x * powerDivideON(x, n - 1);
}

// 3. Divide & Conquer O(log N)
double powerDivideLogN(double x, int n) {
    if (n == 0) return 1;
    double half = powerDivideLogN(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    int base, exp;
    cout << "Enter base (integer): ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exp;

    cout << "Result (Iterative O(n)): "
         << powerIterative(base, exp) << endl;

    cout << "Result (Divide & Conquer O(N)): "
         << powerDivideON(base, exp) << endl;

    cout << "Result (Divide & Conquer O(log N)): "
         << powerDivideLogN(base, exp) << endl;

    return 0;
}
