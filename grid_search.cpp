#include <bits/stdc++.h>
using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    int R = G.size();
    int C = G[0].size();
    int r = P.size();
    int c = P[0].size();

    for (int i = 0; i <= R - r; i++) {
        for (int j = 0; j <= C - c; j++) {
            bool found = true;
            for (int x = 0; x < r; x++) {
                if (G[i + x].substr(j, c) != P[x]) {
                    found = false;
                    break;
                }
            }
            if (found) return "YES";
        }
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<string> G(R);
        for (int i = 0; i < R; i++) {
            cin >> G[i];
        }
        int r, c;
        cin >> r >> c;
        vector<string> P(r);
        for (int i = 0; i < r; i++) {
            cin >> P[i];
        }
        cout << gridSearch(G, P) << endl;
    }
    return 0;
}
