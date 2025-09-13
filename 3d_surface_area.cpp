#include <bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int H = A.size();
    int W = A[0].size();
    int area = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] > 0) {
                // Top and bottom always visible
                area += 2;

                // Check 4 sides
                // Up
                if (i == 0) area += A[i][j];
                else area += max(0, A[i][j] - A[i-1][j]);

                // Down
                if (i == H-1) area += A[i][j];
                else area += max(0, A[i][j] - A[i+1][j]);

                // Left
                if (j == 0) area += A[i][j];
                else area += max(0, A[i][j] - A[i][j-1]);

                // Right
                if (j == W-1) area += A[i][j];
                else area += max(0, A[i][j] - A[i][j+1]);
            }
        }
    }
    return area;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    cout << surfaceArea(A) << endl;
    return 0;
}
