#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100000;

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n) {
        bit.assign(n + 1, 0);
    }
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int sum(int idx) {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

vector<vector<int>> tree;
long long ans = 0;
int k;

void dfs(int u, Fenwick &fw) {
    // count ancestors with label difference ≤ k
    int L = max(1, u - k);
    int R = min((int)fw.n, u + k);

    ans += fw.rangeSum(L, R);

    fw.update(u, 1);  // add current node

    for (int v : tree[u])
        dfs(v, fw);

    fw.update(u, -1); // remove current node
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k;

    tree.assign(n + 1, {});
    vector<int> parentCount(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        parentCount[c] = 1;
    }

    // find the root (node with no parent)
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (!parentCount[i])
            root = i;

    Fenwick fw(n);

    dfs(root, fw);

    cout << ans << "\n";
    return 0;
}
