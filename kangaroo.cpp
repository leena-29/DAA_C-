#include <iostream>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 == v2) {
        if (x1 == x2) return "YES";
        else return "NO";
    }
    if ((x2 - x1) % (v1 - v2) == 0 && (v1 - v2) * (x2 - x1) < 0) return "YES";
    return "NO";
}

int main() {
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    cout << kangaroo(x1, v1, x2, v2) << endl;
    return 0;
}
