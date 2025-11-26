#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int link;
    vector<int> out; 
    Node() {
        memset(next, -1, sizeof(next));
        link = -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> genes(n);
    for (int i = 0; i < n; i++)
        cin >> genes[i];

    vector<long long> health(n);
    for (int i = 0; i < n; i++)
        cin >> health[i];

    // Group gene indexes by gene string
    unordered_map<string, vector<int>> geneIndex;
    for (int i = 0; i < n; i++)
        geneIndex[genes[i]].push_back(i);

    // Build Aho-Corasick trie
    vector<Node> trie(1);

    for (auto &g : geneIndex) {
        int node = 0;
        for (char c : g.first) {
            int x = c - 'a';
            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[x];
        }
        for (int id : g.second)
            trie[node].out.push_back(id);
    }

    // Build failure links
    queue<int> q;
    trie[0].link = 0;

    for (int c = 0; c < 26; c++) {
        int nxt = trie[0].next[c];
        if (nxt != -1) {
            trie[nxt].link = 0;
            q.push(nxt);
        } else {
            trie[0].next[c] = 0;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int c = 0; c < 26; c++) {
            int nxt = trie[v].next[c];
            if (nxt != -1) {
                trie[nxt].link = trie[trie[v].link].next[c];
                auto &outLink = trie[trie[nxt].link].out;
                trie[nxt].out.insert(trie[nxt].out.end(), outLink.begin(), outLink.end());
                q.push(nxt);
            } else {
                trie[v].next[c] = trie[trie[v].link].next[c];
            }
        }
    }

    int qCount;
    cin >> qCount;

    long long minHealth = LLONG_MAX, maxHealth = LLONG_MIN;

    while (qCount--) {
        int L, R;
        string d;
        cin >> L >> R >> d;

        long long total = 0;
        int node = 0;

        for (char c : d) {
            node = trie[node].next[c - 'a'];
            for (int id : trie[node].out) {
                if (id >= L && id <= R)
                    total += health[id];
            }
        }

        minHealth = min(minHealth, total);
        maxHealth = max(maxHealth, total);
    }

    cout << minHealth << " " << maxHealth;
    return 0;
}
