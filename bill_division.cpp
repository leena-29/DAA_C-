#include <iostream>
#include <vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
    int sum = 0;
    for (int i = 0; i < bill.size(); i++) {
        if (i != k) sum += bill[i];
    }
    int fair_share = sum / 2;
    if (b == fair_share)
        cout << "Bon Appetit" << endl;
    else
        cout << b - fair_share << endl;
}

int main() {
    int n, k, b;
    cin >> n >> k;
    vector<int> bill(n);
    for (int i = 0; i < n; i++) cin >> bill[i];
    cin >> b;
    bonAppetit(bill, k, b);
    return 0;
}
