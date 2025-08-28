#include <bits/stdc++.h>
using namespace std;

string biggerIsGreater(string w) {
    int n = w.size();

    // Step 1: Find longest non-increasing suffix
    int i = n - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }

    // If entire string is non-increasing, no answer
    if (i < 0) {
        return "no answer";
    }

    // Step 2: Find rightmost successor to pivot
    int j = n - 1;
    while (w[j] <= w[i]) {
        j--;
    }

    // Step 3: Swap pivot with successor
    swap(w[i], w[j]);

    // Step 4: Reverse the suffix
    reverse(w.begin() + i + 1, w.end());

    return w;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string w;
        cin >> w;
        cout << biggerIsGreater(w) << endl;
    }
    return 0;
}
