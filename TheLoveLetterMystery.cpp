#include <bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string s) {
    int n = s.length();
    int operations = 0;

    int l = 0, r = n - 1;
    while (l < r) {
        operations += abs(s[l] - s[r]);
        l++;
        r--;
    }
    return operations;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << theLoveLetterMystery(s) << endl;
    }
    return 0;
}
