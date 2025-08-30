#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    unordered_set<int> values(arr.begin(), arr.end());
    int count = 0;

    for (int x : arr) {
        if (values.count(x + d) && values.count(x + 2 * d)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << beautifulTriplets(d, arr) << endl;
    return 0;
}
