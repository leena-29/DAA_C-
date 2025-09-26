#include <bits/stdc++.h>
using namespace std;

int camelcase(string s) {
    int count = 1; // first word is always lowercase
    for (char c : s) {
        if (isupper(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << camelcase(s) << endl;
    return 0;
}
