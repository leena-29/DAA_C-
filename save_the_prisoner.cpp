#include <iostream>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    int result = (s + m - 1) % n;
    return (result == 0) ? n : result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        cout << saveThePrisoner(n, m, s) << endl;
    }

    return 0;
}
