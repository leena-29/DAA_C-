#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int r, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Directions for movement
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    // Map each free cell to an index
    vector<vector<int>> id(n, vector<int>(m, -1));
    int cnt = 0;
    int start = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c = grid[i][j];
            if(c != '#'){
                id[i][j] = cnt++;
                if(c == 'A') start = id[i][j];
            }
        }
    }

    // Tunnel mapping
    vector<int> tunnel(cnt, -1);
    for(int i = 0; i < t; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;

        int a = id[r1][c1];
        int b = id[r2][c2];
        tunnel[a] = b;
        tunnel[b] = a;
    }

    // Build equations for linear system
    vector<vector<double>> A(cnt, vector<double>(cnt, 0.0));
    vector<double> B(cnt, 0.0);

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(id[r][c] == -1) continue;
            int u = id[r][c];
            char cell = grid[r][c];

            if(cell == '%'){
                A[u][u] = 1;
                B[u] = 1; // Already escaped
                continue;
            }
            if(cell == '*'){
                A[u][u] = 1;
                B[u] = 0; // Dead
                continue;
            }

            // Check if this cell has a tunnel
            if(tunnel[u] != -1){
                int v = tunnel[u];
                A[u][u] = -1;
                A[u][v] = 1;
                continue;
            }

            // Normal free or A cell
            vector<int> nxt;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(grid[nr][nc] != '#'){
                        nxt.push_back(id[nr][nc]);
                    }
                }
            }

            int deg = nxt.size();
            A[u][u] = -1;
            if(deg == 0){
                B[u] = 0;
                continue;
            }

            double p = 1.0 / deg;
            for(int v : nxt){
                A[u][v] = p;
            }
        }
    }

    // Solve A*x = B using Gaussian elimination
    int N = cnt;
    for(int i = 0; i < N; i++){
        int pivot = i;
        for(int j = i + 1; j < N; j++){
            if(abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        }
        swap(A[i], A[pivot]);
        swap(B[i], B[pivot]);

        double div = A[i][i];
        for(int j = i; j < N; j++) A[i][j] /= div;
        B[i] /= div;

        for(int j = 0; j < N; j++){
            if(j != i){
                double factor = A[j][i];
                for(int k = i; k < N; k++){
                    A[j][k] -= factor * A[i][k];
                }
                B[j] -= factor * B[i];
            }
        }
    }

    cout << fixed << setprecision(10) << B[start] << "\n";
    return 0;
}
