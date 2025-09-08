#include <bits/stdc++.h>
using namespace std;

vector<string> cavityMap(vector<string> grid) {
    int n = grid.size();
    vector<string> result = grid;  // Copy original grid
    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            char cell = grid[i][j];
            if (cell > grid[i-1][j] && 
                cell > grid[i+1][j] && 
                cell > grid[i][j-1] && 
                cell > grid[i][j+1]) {
                result[i][j] = 'X';
            }
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<string> result = cavityMap(grid);
    for (string row : result) {
        cout << row << "\n";
    }

    return 0;
}
