#include <bits/stdc++.h>
using namespace std;

int chocolateFeast(int n, int c, int m) {
    int chocolates = n / c;
    int wrappers = chocolates;
    while (wrappers >= m) {
        int newChocolates = wrappers / m;
        chocolates += newChocolates;
        wrappers = wrappers % m + newChocolates;
    }
    return chocolates;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolateFeast(n, c, m) << endl;
    }
    return 0;
}
