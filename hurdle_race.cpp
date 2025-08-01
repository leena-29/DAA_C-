#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hurdleRace(int k, vector<int> height) {
    int max_height = *max_element(height.begin(), height.end());
    return max(0, max_height - k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = hurdleRace(k, height);
    cout << result << endl;

    return 0;
}
