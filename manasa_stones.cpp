#include <bits/stdc++.h>
using namespace std;

vector<int> stones(int n, int a, int b) {
    set<int> results;  // Use set to avoid duplicates and keep sorted
    
    for (int i = 0; i < n; i++) {
        int lastStone = i * a + (n - 1 - i) * b;
        results.insert(lastStone);
    }
    
    return vector<int>(results.begin(), results.end());
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans = stones(n, a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
        }
    }
    
    return 0;
}
