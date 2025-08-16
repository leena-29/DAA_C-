#include <bits/stdc++.h>
using namespace std;

int squares(int a, int b) {
    // Smallest integer whose square is >= a
    int start = ceil(sqrt(a));
    // Largest integer whose square is <= b
    int end = floor(sqrt(b));
    
    // Number of integers between start and end inclusive
    return max(0, end - start + 1);
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << squares(a, b) << endl;
    }
    return 0;
}

