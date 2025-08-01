#include <iostream>
using namespace std;

int countingValleys(int steps, string path) {
    int level = 0, valleys = 0;
    for (char step : path) {
        if (step == 'U') {
            level++;
            if (level == 0) valleys++;
        } else {
            level--;
        }
    }
    return valleys;
}

int main() {
    int steps;
    string path;
    cin >> steps >> path;
    cout << countingValleys(steps, path);
    return 0;
}
