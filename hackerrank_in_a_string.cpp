#include <bits/stdc++.h>
using namespace std;

string hackerrankInString(string s) {
    string target = "hackerrank";
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[j]) j++;
        if (j == target.size()) return "YES";
    }
    return "NO";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << hackerrankInString(s) << endl;
    }
    return 0;
}
