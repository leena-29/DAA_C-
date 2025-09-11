#include <bits/stdc++.h>
using namespace std;

string happyLadybugs(string b) {
    int n = b.size();
    unordered_map<char, int> freq;
    bool hasEmpty = false;

    for (char ch : b) {
        if (ch == '_') hasEmpty = true;
        else freq[ch]++;
    }

    // If no empty cell, check if all are already happy
    if (!hasEmpty) {
        for (int i = 0; i < n; i++) {
            if ((i > 0 && b[i] == b[i - 1]) || (i < n - 1 && b[i] == b[i + 1])) {
                continue;
            } else {
                return "NO";
            }
        }
        return "YES";
    }

    // If there are empty cells, check no color has only 1 ladybug
    for (auto &p : freq) {
        if (p.second == 1) return "NO";
    }
    return "YES";
}

int main() {
    int g;
    cin >> g;
    while (g--) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        cout << happyLadybugs(b) << endl;
    }
    return 0;
}
