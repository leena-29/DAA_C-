#include <bits/stdc++.h>
using namespace std;

int howManyGames(int p, int d, int m, int s) {
    int games = 0;
    int cost = p;

    while (s >= cost) {
        s -= cost;
        games++;
        cost = max(m, cost - d);
    }
    return games;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    cout << howManyGames(p, d, m, s) << endl;
    return 0;
}
