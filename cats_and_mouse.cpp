#include <iostream>
#include <cmath>
using namespace std;

string catAndMouse(int x, int y, int z) {
    int distA = abs(x - z);
    int distB = abs(y - z);
    if (distA < distB) return "Cat A";
    else if (distB < distA) return "Cat B";
    else return "Mouse C";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << catAndMouse(x, y, z) << endl;
    }
    return 0;
}
