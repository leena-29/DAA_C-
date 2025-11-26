#include <iostream>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[50];

    cout << "Enter JobID Deadline Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs by profit descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    char schedule[50];
    for (int i = 0; i < maxDeadline; i++)
        schedule[i] = '-';

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int t = jobs[i].deadline - 1; t >= 0; t--) {
            if (schedule[t] == '-') {
                schedule[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job Order: ";
    for (int i = 0; i < maxDeadline; i++)
        cout << schedule[i] << " ";

    cout << "\nTotal Profit: " << totalProfit;

    return 0;
}
