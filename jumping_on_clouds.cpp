#include <bits/stdc++.h>
using namespace std;

int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    int i = 0;
    int n = c.size();

    while (i < n - 1) {
        if (i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i += 1;
        }
        jumps++;
    }
    return jumps;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cout << jumpingOnClouds(c) << endl;
    return 0;
}
