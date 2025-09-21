#include <bits/stdc++.h>
using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int layers = min(m, n) / 2;

    // Result matrix
    vector<vector<int>> res = matrix;

    for (int layer = 0; layer < layers; layer++) {
        vector<int> elems;

        // Top row
        for (int j = layer; j < n - layer; j++) elems.push_back(matrix[layer][j]);
        // Right column
        for (int i = layer + 1; i < m - layer - 1; i++) elems.push_back(matrix[i][n - layer - 1]);
        // Bottom row
        for (int j = n - layer - 1; j >= layer; j--) elems.push_back(matrix[m - layer - 1][j]);
        // Left column
        for (int i = m - layer - 2; i > layer; i--) elems.push_back(matrix[i][layer]);

        int len = elems.size();
        int rot = r % len;

        // Rotate elements
        rotate(elems.begin(), elems.begin() + rot, elems.end());

        int idx = 0;
        // Fill Top row
        for (int j = layer; j < n - layer; j++) res[layer][j] = elems[idx++];
        // Fill Right column
        for (int i = layer + 1; i < m - layer - 1; i++) res[i][n - layer - 1] = elems[idx++];
        // Fill Bottom row
        for (int j = n - layer - 1; j >= layer; j--) res[m - layer - 1][j] = elems[idx++];
        // Fill Left column
        for (int i = m - layer - 2; i > layer; i--) res[i][layer] = elems[idx++];
    }

    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int m, n, r;
    cin >> m >> n >> r;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    matrixRotation(matrix, r);
    return 0;
}
