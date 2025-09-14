#include <bits/stdc++.h>
using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> result(n + 1, 0); // 1-based indexing

    if (k == 0) {
        for (int i = 1; i <= n; i++) result[i] = i;
        return result;
    }

    if (n % (2 * k) != 0) return {-1};

    bool add = true;
    for (int i = 1; i <= n; i++) {
        if (add) result[i] = i + k;
        else result[i] = i - k;

        if (i % k == 0) add = !add;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans = absolutePermutation(n, k);

        if (ans.size() == 1 && ans[0] == -1) {
            cout << -1 << "\n";
        } else {
            for (int i = 1; i <= n; i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
