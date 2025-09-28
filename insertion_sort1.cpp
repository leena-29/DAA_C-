#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort1(int n, vector<int> arr) {
    int key = arr[n - 1]; // last element to be inserted
    int i = n - 2;
    
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i]; // shift element right
        printArray(arr);
        i--;
    }
    arr[i + 1] = key; // place key in correct position
    printArray(arr);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort1(n, arr);
    return 0;
}
