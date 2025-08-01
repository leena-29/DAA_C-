#include <iostream>
using namespace std;

int utopianTree(int n) {
    int height = 1;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            height *= 2;
        } else {
            height += 1;
        }
    }
    return height;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << utopianTree(n) << endl;
    }
    return 0;
}
