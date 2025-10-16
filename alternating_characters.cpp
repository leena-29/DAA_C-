#include <bits/stdc++.h>
using namespace std;

int alternatingCharacters(string s) {
    int deletions = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])  // same adjacent characters
            deletions++;
    }
    return deletions;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << alternatingCharacters(s) << endl;
    }
    return 0;
}
