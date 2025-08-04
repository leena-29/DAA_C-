#include <iostream>
#include <cmath>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int beautifulDays(int i, int j, int k) {
    int count = 0;
    for (int day = i; day <= j; day++) {
        int rev = reverseNumber(day);
        if (abs(day - rev) % k == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;

    cout << beautifulDays(i, j, k) << endl;
    return 0;
}
