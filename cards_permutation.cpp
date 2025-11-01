#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long fact[100005];
long long invfact[100005];

// Function to compute (a^b) % MOD
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Modular inverse of factorial
void precomputeFactorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invfact[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    precomputeFactorials(n);

    vector<int> missing;
    vector<bool> present(n + 1, false);

    for (int i = 0; i < n; i++) {
        if (arr[i]) present[arr[i]] = true;
        else missing.push_back(i);
    }

    vector<int> missingNumbers;
    for (int i = 1; i <= n; i++) {
        if (!present[i]) missingNumbers.push_back(i);
    }

    long long result = 0;
    sort(missingNumbers.begin(), missingNumbers.end());

    do {
        vector<int> temp = arr;
        int idx = 0;
        for (int i = 0; i < n; i++)
            if (temp[i] == 0) temp[i] = missingNumbers[idx++];

        // Compute lexicographical position
        vector<int> smaller(n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = temp[i] + 1; j <= n; j++) smaller[j]++;
        }

        long long lineNumber = 1;
        for (int i = 0; i < n; i++) {
            lineNumber = (lineNumber + smaller[temp[i]] * fact[n - i - 1]) % MOD;
            for (int j = temp[i] + 1; j <= n; j++) smaller[j]--;
        }

        result = (result + lineNumber) % MOD;

    } while (next_permutation(missingNumbers.begin(), missingNumbers.end()));

    cout << result % MOD << "\n";
    return 0;
}
