#include <bits/stdc++.h>
using namespace std;

vector<int> acmTeam(vector<string> topic) {
    int n = topic.size();
    int m = topic[0].size();
    int maxTopics = 0;
    int teamCount = 0;

    // Iterate over all pairs of attendees
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int topicsKnown = 0;
            for (int k = 0; k < m; k++) {
                if (topic[i][k] == '1' || topic[j][k] == '1') {
                    topicsKnown++;
                }
            }
            if (topicsKnown > maxTopics) {
                maxTopics = topicsKnown;
                teamCount = 1;
            } else if (topicsKnown == maxTopics) {
                teamCount++;
            }
        }
    }

    return {maxTopics, teamCount};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);
    for (int i = 0; i < n; i++) {
        cin >> topic[i];
    }

    vector<int> result = acmTeam(topic);
    cout << result[0] << endl << result[1] << endl;
    return 0;
}
