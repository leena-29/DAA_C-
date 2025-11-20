#include <bits/stdc++.h>
using namespace std;

vector<int> acmTeam(vector<string> topic) {
    int n = topic.size();
    int maxTopics = 0;
    int teamCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int count = 0;
            for (int k = 0; k < topic[i].size(); k++) {
                if (topic[i][k] == '1' || topic[j][k] == '1')
                    count++;
            }

            if (count > maxTopics) {
                maxTopics = count;
                teamCount = 1;
            }
            else if (count == maxTopics) {
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
    cout << result[0] << "\n" << result[1] << "\n";

    return 0;
}
