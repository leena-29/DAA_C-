#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        string top, bottom;
        cin >> top >> bottom;

        set<string> paths;
        string path1, path2;
        for (int i = 0; i < n; i++) {
            path1 += top[i];
            path1 += bottom[i];
        }
        for (int i = 0; i < n; i++) {
            path2 += bottom[i];
            path2 += top[i];
        }
        paths.insert(path1);
        paths.insert(path2);

        if (n == 3) {
            set<string> local;
            vector<int> order = {0, 1, 2, 3, 4, 5};
            do {
                string temp;
                for (int x : order) {
                    if (x < 3) temp += top[x];
                    else temp += bottom[x - 3];
                }
                local.insert(temp);
            } while (next_permutation(order.begin(), order.end()));
            paths.insert(local.begin(), local.end());
        }

        cout << paths.size() << "\n";
    }
    return 0;
}
