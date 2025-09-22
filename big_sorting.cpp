#include <bits/stdc++.h>
using namespace std;

// Comparator for sorting numeric strings
bool compareNumbers(const string &a, const string &b) {
    if (a.size() == b.size())
        return a < b;  // if same length, compare lexicographically
    return a.size() < b.size(); // otherwise, shorter string is smaller
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compareNumbers);

    for (string &num : arr) {
        cout << num << "\n";
    }
    return 0;
}
