#include <iostream>
#include <cmath>
using namespace std;

int karatsuba(int x, int y) {
    if (x < 10 && y < 10)
        return x * y;

    int n = max((int)log10(x) + 1, (int)log10(y) + 1);
    int half = n / 2;

    int a = x / pow(10, half);
    int b = x % (int)pow(10, half);

    int c = y / pow(10, half);
    int d = y % (int)pow(10, half);

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int adbc = karatsuba(a + b, c + d) - ac - bd;

    return ac * pow(10, 2 * half) + adbc * pow(10, half) + bd;
}

int main() {
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    cout << "Karatsuba Result: " << karatsuba(x, y);
    return 0;
}
