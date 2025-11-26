#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
 for(int i = 1; i < n; i++) {
 int current = arr[i];
 int j = i - 1;
 while(j >= 0 && arr[j] > current) {
 arr[j + 1] = arr[j];
 j--;
 }
 arr[j + 1] = current;
 }
}
int main() {
 int n;
 cout << "Enter the number of elements: ";
 cin >> n;
 int arr[n]; 
cout << "Enter " << n << " elements:\n";
 for(int i = 0; i < n; i++) {
 cin >> arr[i];
 }
 cout << "Original array: ";
 for(int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 insertionSort(arr, n);
 cout << "\nSorted array: ";
 for(int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 return 0;
}
