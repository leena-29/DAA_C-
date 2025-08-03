#include <iostream>
#include <vector>
using namespace std;

string angryProfessor(int k, vector<int> a) {
    int onTime = 0;

    for (int arrival : a) {
        if (arrival <= 0)
            onTime++;
    }

    return (onTime < k) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << angryProfessor(k, a) << endl;
    }

    return 0;
}
