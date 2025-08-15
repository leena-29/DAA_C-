#include <bits/stdc++.h>
using namespace std;

string appendAndDelete(string s, string t, int k) {
    // Find common prefix length
    int commonLength = 0;
    while (commonLength < s.size() && commonLength < t.size() && s[commonLength] == t[commonLength]) {
        commonLength++;
    }

    // Calculate minimum number of operations required
    int minOps = (s.size() - commonLength) + (t.size() - commonLength);

    // Check conditions for "Yes"
    if (minOps > k) return "No";
    else if ((k - minOps) % 2 == 0) return "Yes";
    else if (k >= s.size() + t.size()) return "Yes"; // Can delete all and rebuild
    else return "No";
}

int main() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    cout << appendAndDelete(s, t, k) << endl;
    return 0;
}
