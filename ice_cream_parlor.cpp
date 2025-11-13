#include <bits/stdc++.h>
using namespace std;

vector<int> icecreamParlor(int m, vector<int>& cost) {
    unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < (int)cost.size(); i++) {
        int needed = m - cost[i];
        if (seen.count(needed)) {
            return {seen[needed] + 1, i + 1}; // +1 for 1-based index
        }
        seen[cost[i]] = i;
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> cost(n);
        for (int i = 0; i < n; i++)
            cin >> cost[i];

        vector<int> res = icecreamParlor(m, cost);
        cout << res[0] << " " << res[1] << "\n";
    }
    return 0;
}
