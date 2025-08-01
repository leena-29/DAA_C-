#include <iostream>
#include <vector>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ar[i] + ar[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    cout << divisibleSumPairs(n, k, ar) << endl;
    return 0;
}
