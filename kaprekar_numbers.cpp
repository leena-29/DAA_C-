#include <bits/stdc++.h>
using namespace std;

void kaprekarNumbers(int p, int q) {
    bool found = false;

    for (long long n = p; n <= q; n++) {
        long long sq = n * n;
        string s = to_string(sq);
        int d = to_string(n).size();

        string right = s.substr(s.size() - d, d);  // last d digits
        string left = (s.size() - d > 0) ? s.substr(0, s.size() - d) : "0"; // remaining digits

        long long L = stoll(left);
        long long R = stoll(right);

        if (L + R == n) {
            cout << n << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "INVALID RANGE";
    }
    cout << endl;
}

int main() {
    int p, q;
    cin >> p >> q;
    kaprekarNumbers(p, q);
    return 0;
}
