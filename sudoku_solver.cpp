#include <iostream>
using namespace std;

int grid[9][9];

bool isSafe(int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) return false;
        if (grid[x][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (grid[row][col] == 0) {

                for (int num = 1; num <= 9; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku())
                            return true;

                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter 9x9 Sudoku grid (use 0 for empty cells):\n";

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    if (solveSudoku()) {
        cout << "\nSolved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
