#include <iostream>
#include <vector>
using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int maxScore = scores[0];
    int minScore = scores[0];
    int maxCount = 0;
    int minCount = 0;

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxCount++;
        } else if (scores[i] < minScore) {
            minScore = scores[i];
            minCount++;
        }
    }

    return {maxCount, minCount};
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<int> result = breakingRecords(scores);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
