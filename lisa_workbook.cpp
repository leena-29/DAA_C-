#include <bits/stdc++.h>
using namespace std;

int workbook(int n, int k, vector<int> arr) {
    int page = 1, special = 0;
    for (int i = 0; i < n; i++) {
        for (int problem = 1; problem <= arr[i]; problem++) {
            if (problem == page) special++;
            if (problem % k == 0 || problem == arr[i]) page++;
        }
    }
    return special;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << workbook(n, k, arr) << endl;
    return 0;
}
