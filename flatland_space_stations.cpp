#include <bits/stdc++.h>
using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    sort(c.begin(), c.end());

    int maxDist = 0;

    // distance from city 0 to first space station
    maxDist = max(maxDist, c[0] - 0);

    // distance from last city to last space station
    maxDist = max(maxDist, (n - 1) - c.back());

    // check max gap between consecutive stations
    for (int i = 1; i < c.size(); i++) {
        int gap = (c[i] - c[i-1]) / 2;
        maxDist = max(maxDist, gap);
    }

    return maxDist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) cin >> c[i];

    cout << flatlandSpaceStations(n, c) << endl;
    return 0;
}
