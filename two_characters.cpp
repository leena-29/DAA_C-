#include <bits/stdc++.h>
using namespace std;

// Check if string is valid alternating
bool isValid(const string &s) {
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int alternate(string s) {
    int n = s.size();
    int ans = 0;

    // Collect unique characters
    set<char> chars(s.begin(), s.end());
    vector<char> unique(chars.begin(), chars.end());

    // Try all pairs of distinct characters
    for (int i = 0; i < (int)unique.size(); i++) {
        for (int j = i + 1; j < (int)unique.size(); j++) {
            char c1 = unique[i], c2 = unique[j];
            string filtered = "";
            
            // Keep only c1 and c2
            for (char c : s) {
                if (c == c1 || c == c2) filtered.push_back(c);
            }

            // Check if alternating
            if (isValid(filtered)) {
                ans = max(ans, (int)filtered.size());
            }
        }
    }

    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << alternate(s) << endl;
    return 0;
}
