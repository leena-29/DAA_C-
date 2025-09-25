#include <bits/stdc++.h>
using namespace std;

int introTutorial(int V, vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == V) {
            return i;
        }
    }
    return -1; // though problem guarantees V exists exactly once
}

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << introTutorial(V, arr) << endl;
    return 0;
}
