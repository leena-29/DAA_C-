#include <bits/stdc++.h>
using namespace std;

void almostSorted(vector<int> arr) {
    int n = arr.size();
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    if (arr == sortedArr) {
        cout << "yes" << endl;
        return;
    }

    // Find first and last index where array differs from sorted
    int l = 0, r = n - 1;
    while (l < n && arr[l] == sortedArr[l]) l++;
    while (r >= 0 && arr[r] == sortedArr[r]) r--;

    // Try swap
    swap(arr[l], arr[r]);
    if (arr == sortedArr) {
        cout << "yes" << endl;
        cout << "swap " << l + 1 << " " << r + 1 << endl;
        return;
    }

    // Undo swap and try reverse
    swap(arr[l], arr[r]);
    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (arr == sortedArr) {
        cout << "yes" << endl;
        cout << "reverse " << l + 1 << " " << r + 1 << endl;
        return;
    }

    cout << "no" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    almostSorted(arr);
    return 0;
}
