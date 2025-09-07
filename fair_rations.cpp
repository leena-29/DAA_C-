#include <bits/stdc++.h>
using namespace std;

string fairRations(vector<int> B) {
    int n = B.size();
    int loaves = 0;

    for (int i = 0; i < n - 1; i++) {
        if (B[i] % 2 != 0) {
            B[i]++;
            B[i + 1]++;
            loaves += 2;
        }
    }

    if (B[n - 1] % 2 != 0) return "NO";
    return to_string(loaves);
}

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> B[i];

    cout << fairRations(B) << endl;
    return 0;
}
