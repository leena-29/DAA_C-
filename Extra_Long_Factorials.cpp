#include <iostream>
#include <vector>
using namespace std;

void extraLongFactorials(int n) {
    vector<int> result; 
    result.push_back(1); // factorial starts with 1

    for (int x = 2; x <= n; x++) {
        int carry = 0;
        for (int i = 0; i < result.size(); i++) {
            int prod = result[i] * x + carry;
            result[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print in reverse order (most significant digit first)
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
