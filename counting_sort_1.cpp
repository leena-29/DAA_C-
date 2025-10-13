#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> count(100, 0);  // Frequency array with 100 elements
    for (int num : arr) {
        count[num]++;  // Increment count for each number
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    vector<int> result = countingSort(arr);
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
        
    return 0;
}
