#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> result;
    vector<int> uniqueRanked;
    uniqueRanked.push_back(ranked[0]);
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] != ranked[i - 1]) {
            uniqueRanked.push_back(ranked[i]);
        }
    }

    int n = uniqueRanked.size();
    int index = n - 1;

    for (int i = 0; i < player.size(); i++) {
        while (index >= 0 && player[i] >= uniqueRanked[index]) {
            index--;
        }
        result.push_back(index + 2);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ranked(n);
    for (int i = 0; i < n; i++) {
        cin >> ranked[i];
    }

    int m;
    cin >> m;
    vector<int> player(m);
    for (int i = 0; i < m; i++) {
        cin >> player[i];
    }

    vector<int> result = climbingLeaderboard(ranked, player);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
