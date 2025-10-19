
#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    vector<int> result;
    
    for (int i = 1; i < arr.size(); i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.clear();
            result.push_back(arr[i - 1]);
            result.push_back(arr[i]);
        } else if (diff == minDiff) {
            result.push_back(arr[i - 1]);
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> ans = closestNumbers(arr);
    for (int x : ans) cout << x << " ";
    return 0;
}
