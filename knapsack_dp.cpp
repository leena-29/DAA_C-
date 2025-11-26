#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    int weight[50], value[50];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[50][50];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value in knapsack = " << dp[n][capacity];
    return 0;
}
