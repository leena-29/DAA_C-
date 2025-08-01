#include <iostream>
#include <vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int maxSpent = -1;
    for (int i = 0; i < keyboards.size(); i++) {
        for (int j = 0; j < drives.size(); j++) {
            int total = keyboards[i] + drives[j];
            if (total <= b && total > maxSpent) {
                maxSpent = total;
            }
        }
    }
    return maxSpent;
}

int main() {
    int b, n, m;
    cin >> b >> n >> m;
    vector<int> keyboards(n);
    vector<int> drives(m);
    for (int i = 0; i < n; i++) cin >> keyboards[i];
    for (int i = 0; i < m; i++) cin >> drives[i];
    cout << getMoneySpent(keyboards, drives, b);
    return 0;
}
