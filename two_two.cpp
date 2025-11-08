#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(const string &s, const unordered_set<string> &powers) {
    return powers.find(s) != powers.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute all powers of 2 up to 2^800 as strings
    unordered_set<string> powers;
    vector<string> listPowers;
    __int128 num = 1;
    for (int i = 0; i <= 800; i++) {
        string s;
        __int128 temp = num;
        if (temp == 0) s = "0";
        else {
            while (temp > 0) {
                s.push_back('0' + (temp % 10));
                temp /= 10;
            }
            reverse(s.begin(), s.end());
        }
        powers.insert(s);
        listPowers.push_back(s);
        num *= 2;
    }

    int T;
    cin >> T;
    while (T--) {
        string A;
        cin >> A;
        int n = A.size();
        long long count = 0;

        // To avoid checking too long substrings, limit max power length
        int maxLen = listPowers.back().size();

        for (int i = 0; i < n; i++) {
            if (A[i] == '0') continue; // skip leading zero
            string sub = "";
            for (int j = i; j < n && j - i < maxLen; j++) {
                sub.push_back(A[j]);
                if (isPowerOfTwo(sub, powers))
                    count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
