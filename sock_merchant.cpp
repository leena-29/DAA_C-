#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> colorCount;
    int pairs = 0;
    for (int color : ar) colorCount[color]++;
    for (auto entry : colorCount) pairs += entry.second / 2;
    return pairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    cout << sockMerchant(n, ar) << endl;
    return 0;
}
