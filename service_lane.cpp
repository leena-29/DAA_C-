#include <bits/stdc++.h>
using namespace std;

vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int> result;
    for (auto &c : cases) {
        int l = c[0], r = c[1];
        int mn = *min_element(width.begin() + l, width.begin() + r + 1);
        result.push_back(mn);
    }
    return result;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> width(n);
    for (int i = 0; i < n; i++) cin >> width[i];
    vector<vector<int>> cases(t, vector<int>(2));
    for (int i = 0; i < t; i++) cin >> cases[i][0] >> cases[i][1];
    vector<int> ans = serviceLane(n, width, cases);
    for (int x : ans) cout << x << endl;
    return 0;
}
