#include <bits/stdc++.h>
using namespace std;

string funnyString(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    for (int i = 1; i < s.size(); i++) {
        int diff1 = abs(s[i] - s[i - 1]);
        int diff2 = abs(rev[i] - rev[i - 1]);
        if (diff1 != diff2)
            return "Not Funny";
    }
    return "Funny";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << funnyString(s) << endl;
    }
    return 0;
}
