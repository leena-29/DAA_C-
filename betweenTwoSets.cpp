#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int getTotalX(vector<int> a, vector<int> b) {
    int lcm_a = a[0];
    for (int i = 1; i < a.size(); i++) {
        lcm_a = lcm(lcm_a, a[i]);
    }

    int gcd_b = b[0];
    for (int i = 1; i < b.size(); i++) {
        gcd_b = gcd(gcd_b, b[i]);
    }

    int count = 0;
    for (int i = lcm_a; i <= gcd_b; i += lcm_a) {
        if (gcd_b % i == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int total = getTotalX(a, b);
    cout << total << endl;

    return 0;
}
