#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> freq(k, 0);

    for (int num : S) {
        freq[num % k]++;
    }

    int result = min(1, freq[0]);
    for (int i = 1; i <= k/2; i++) {
        if (i == k - i) {
            result += 1;
        } else {
            result += max(freq[i], freq[k - i]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cout << nonDivisibleSubset(k, S) << "\n";
    return 0;
}
