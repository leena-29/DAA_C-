#include <bits/stdc++.h>
using namespace std;

int runningTime(vector<int> arr) {
    int shifts = 0;
    for (int i = 1; i < arr.size(); i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = current;
    }
    return shifts;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << runningTime(arr) << endl;
    return 0;
}
