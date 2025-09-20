#include <bits/stdc++.h>
using namespace std;

string larrysArray(vector<int> A) {
    int inversions = 0;
    int n = A.size();

    // Count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) inversions++;
        }
    }

    // If inversions count is even => sortable
    return (inversions % 2 == 0) ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cout << larrysArray(A) << "\n";
    }
    return 0;
}
