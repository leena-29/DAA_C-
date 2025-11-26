#include <iostream>
using namespace std;
void countingSort(int arr[], int n) {
 int maxElement = arr[0];
 for(int i = 1; i < n; i++) {
 if(arr[i] > maxElement)
 maxElement = arr[i];
 }
 int count[maxElement + 1] = {0};
 for(int i = 0; i < n; i++) {
 count[arr[i]]++;
 }
 int index = 0;
 for(int i = 0; i <= maxElement; i++) {
while(count[i] > 0) {
 arr[index++] = i;
 count[i]--;
 }
 }
}
int main() {
 int n;
 cout << "Enter the number of elements: ";
 cin >> n;
 int arr[n];
 cout << "Enter " << n << " non-negative integers:\n";
 for(int i = 0; i < n; i++) {
 cin >> arr[i];
 }
 cout << "Original array: ";
 for(int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 countingSort(arr, n);
 cout << "\nSorted array: ";
 for(int i = 0; i < n; i++) {
 cout << arr[i] << " ";
}
 return 0;
}
