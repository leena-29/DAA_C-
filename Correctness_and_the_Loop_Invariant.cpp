#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int N, int arr[]) {
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print the fully sorted array
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N; // Size of the array
    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Input array elements
    }

    insertionSort(N, arr);

    return 0;
}
