#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, t;
    cin >> s >> t;

    int a, b;
    cin >> a >> b;

    int m, n;
    cin >> m >> n;

    vector<int> apples(m), oranges(n);

    for (int i = 0; i < m; i++) {
        cin >> apples[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> oranges[i];
    }

    int appleCount = 0;
    int orangeCount = 0;

    for (int i = 0; i < m; i++) {
        int position = a + apples[i];
        if (position >= s && position <= t) {
            appleCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        int position = b + oranges[i];
        if (position >= s && position <= t) {
            orangeCount++;
        }
    }

    cout << appleCount << endl;
    cout << orangeCount << endl;

    return 0;
}
