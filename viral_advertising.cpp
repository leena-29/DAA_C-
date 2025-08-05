#include <iostream>
using namespace std;

int viralAdvertising(int n) {
    int shared = 5;
    int liked, cumulative = 0;

    for (int day = 1; day <= n; day++) {
        liked = shared / 2;
        cumulative += liked;
        shared = liked * 3;
    }

    return cumulative;
}

int main() {
    int n;
    cin >> n;

    cout << viralAdvertising(n) << endl;
    return 0;
}
