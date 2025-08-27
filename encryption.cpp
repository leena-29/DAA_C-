#include <bits/stdc++.h>
using namespace std;

string encryption(string s) {
    // remove spaces
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    
    int L = s.length();
    int rows = floor(sqrt(L));
    int cols = ceil(sqrt(L));
    if (rows * cols < L) rows++;

    vector<string> grid;
    for (int i = 0; i < L; i += cols) {
        grid.push_back(s.substr(i, cols));
    }

    string result = "";
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < (int)grid.size(); r++) {
            if (c < (int)grid[r].size()) {
                result += grid[r][c];
            }
        }
        result += " ";
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);

    cout << encryption(s) << endl;
    return 0;
}
