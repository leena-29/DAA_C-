#include <iostream>
using namespace std;

int findDigits(int n) {
    int count = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        temp /= 10;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << findDigits(n) << endl;
    }
    return 0;
}
