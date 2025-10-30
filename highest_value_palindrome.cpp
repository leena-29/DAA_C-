#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    string result = s;
    vector<bool> changed(n, false);
    int l = 0, r = n - 1;

    // Step 1: Make it a palindrome with minimum changes
    while (l < r) {
        if (s[l] != s[r]) {
            result[l] = result[r] = max(s[l], s[r]);
            changed[l] = changed[r] = true;
            k--;
        }
        l++;
        r--;
    }

    if (k < 0) return "-1";

    // Step 2: Maximize palindrome value
    l = 0;
    r = n - 1;
    while (l <= r) {
        if (l == r) {
            if (k > 0) result[l] = '9';
        } else {
            if (result[l] != '9') {
                if (changed[l] && k >= 1) {
                    result[l] = result[r] = '9';
                    k--;
                } else if (!changed[l] && k >= 2) {
                    result[l] = result[r] = '9';
                    k -= 2;
                }
            }
        }
        l++;
        r--;
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    cout << highestValuePalindrome(s, n, k);
    return 0;
}
