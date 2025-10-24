#include <bits/stdc++.h>
using namespace std;

// Function to get median * 2 (to avoid using float)
double getMedian(vector<int>& count, int d) {
    int prefix = 0;
    int m1 = -1, m2 = -1;

    if (d % 2 == 1) {
        int mid = d / 2 + 1;
        for (int i = 0; i < 201; i++) {
            prefix += count[i];
            if (prefix >= mid)
                return 2 * i; // double median for easy comparison
        }
    } else {
        int mid1 = d / 2, mid2 = d / 2 + 1;
        for (int i = 0; i < 201; i++) {
            prefix += count[i];
            if (prefix >= mid1 && m1 == -1)
                m1 = i;
            if (prefix >= mid2) {
                m2 = i;
                break;
            }
        }
        return m1 + m2; // since we are doubling, return sum
    }
    return 0;
}

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count(201, 0); // range 0-200
    int n = expenditure.size();
    int notifications = 0;

    // Initialize frequency array for first d days
    for (int i = 0; i < d; i++)
        count[expenditure[i]]++;

    for (int i = d; i < n; i++) {
        double median2 = getMedian(count, d);
        if (expenditure[i] >= median2)
            notifications++;

        // Update frequency for sliding window
        count[expenditure[i - d]]--;
        count[expenditure[i]]++;
    }

    return notifications;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for (int i = 0; i < n; i++) cin >> expenditure[i];

    cout << activityNotifications(expenditure, d) << "\n";
    return 0;
}
