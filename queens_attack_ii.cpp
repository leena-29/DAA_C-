#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Use a set for quick lookup of obstacles
    set<pair<int,int>> obs;
    for (auto &o : obstacles) {
        obs.insert({o[0], o[1]});
    }

    int count = 0;
    // 8 possible directions (row change, col change)
    vector<pair<int,int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    // Explore each direction until hitting obstacle or edge
    for (auto d : directions) {
        int r = r_q + d.first;
        int c = c_q + d.second;
        while (r >= 1 && r <= n && c >= 1 && c <= n) {
            if (obs.count({r, c})) break; // obstacle blocks path
            count++;
            r += d.first;
            c += d.second;
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}
