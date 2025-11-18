#include <bits/stdc++.h>
using namespace std;

int bfs(int n, int a, int b) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int,int>> q;

    dist[0][0] = 0;
    q.push({0,0});

    vector<pair<int,int>> moves = {
        { a,  b}, { a, -b}, {-a,  b}, {-a, -b},
        { b,  a}, { b, -a}, {-b,  a}, {-b, -a}
    };

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(x == n-1 && y == n-1)
            return dist[x][y];

        for(auto &mv : moves) {
            int nx = x + mv.first;
            int ny = y + mv.second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> ans(n-1, vector<int>(n-1, -1));

    for(int a = 1; a <= n-1; a++){
        for(int b = 1; b <= n-1; b++){
            if(ans[a-1][b-1] != -1) continue;   // symmetry reuse

            int moves = bfs(n, a, b);
            ans[a-1][b-1] = moves;
            ans[b-1][a-1] = moves;  // symmetry: (a,b) == (b,a)
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            cout << ans[i][j];
            if(j < n-2) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
