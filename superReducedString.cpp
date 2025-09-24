#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
    string result = "";
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back(); // remove the last char if it's the same
        } else {
            result.push_back(c);
        }
    }
    return result.empty() ? "Empty String" : result;
}

int main() {
    string s;
    cin >> s;
    cout << superReducedString(s) << endl;
    return 0;
}
