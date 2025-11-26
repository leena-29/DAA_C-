#include <iostream>
using namespace std;

struct Item {
    int weight;
    int value;
};

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[50];

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Compute value/weight ratio
    double ratio[50];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)items[i].value / items[i].weight;
    }

    // Simple bubble sort based on ratio decreasing
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                double tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;

                Item tempI = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempI;
            }
        }
    }

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
    }

    cout << "Total value (Greedy 0/1 Knapsack): " << totalValue;
    return 0;
}
