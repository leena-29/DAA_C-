#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[50], finish[50];

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++)
        cin >> finish[i];

    // Sort by finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int tempF = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = tempF;

                int tempS = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tempS;
            }
        }
    }

    cout << "Selected activities: ";

    int lastFinish = finish[0];
    cout << "( " << start[0] << "," << finish[0] << " ) ";

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "( " << start[i] << "," << finish[i] << " ) ";
            lastFinish = finish[i];
        }
    }

    return 0;
}
