#include <bits/stdc++.h>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int i = 0;
    
    while (i < n) {
        result.push_back(n - i);  // number of sticks before this cut
        int current = arr[i];
        while (i < n && arr[i] == current) {
            i++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = cutTheSticks(arr);
    for (int x : result) {
        cout << x << "\n";
    }
    return 0;
}
