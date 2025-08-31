#include <bits/stdc++.h>
using namespace std;

int minimumDistances(vector<int> a) {
    unordered_map<int, int> lastIndex;
    int minDist = INT_MAX;

    for (int i = 0; i < a.size(); i++) {
        if (lastIndex.find(a[i]) != lastIndex.end()) {
            minDist = min(minDist, i - lastIndex[a[i]]);
        }
        lastIndex[a[i]] = i;
    }

    return (minDist == INT_MAX) ? -1 : minDist;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minimumDistances(arr) << endl;
    return 0;
}
