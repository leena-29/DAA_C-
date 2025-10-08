#include <bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int> arr) {
    int pivot = arr[0];
    vector<int> left, equal, right;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < pivot)
            left.push_back(arr[i]);
        else if (arr[i] == pivot)
            equal.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }

    vector<int> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result = quickSort(arr);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
