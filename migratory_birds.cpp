#include <bits/stdc++.h>
using namespace std;

int migratoryBirds(vector<int> arr) {
    vector<int> freq(6, 0);
    for (int id : arr) {
        freq[id]++;
    }

    int max_freq = 0;
    int bird_id = 0;
    for (int i = 1; i <= 5; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            bird_id = i;
        }
    }

    return bird_id;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << migratoryBirds(arr) << endl;

    return 0;
}
