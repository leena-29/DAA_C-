#include <iostream>
#include <vector>
using namespace std;

int jumpingOnClouds(vector<int> c, int k) {
    int energy = 100;
    int n = c.size();
    int pos = 0;

    do {
        pos = (pos + k) % n;
        energy -= 1; // jump cost
        if (c[pos] == 1) {
            energy -= 2; // thunderhead penalty
        }
    } while (pos != 0);

    return energy;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cout << jumpingOnClouds(c, k) << endl;
    return 0;
}
