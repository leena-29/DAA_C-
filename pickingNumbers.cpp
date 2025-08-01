#include <bits/stdc++.h>
using namespace std;

int pickingNumbers(vector<int> a) {
    vector<int> freq(101, 0);

    for (int num : a) {
        freq[num]++;
    }

    int max_len = 0;

    for (int i = 1; i <= 100; i++) {
        max_len = max(max_len, freq[i] + freq[i - 1]);
    }

    return max_len;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << pickingNumbers(a) << endl;

    return 0;
}
