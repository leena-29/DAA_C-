#include <iostream>
using namespace std;

int graph[10][10], visited[10];

void dfs(int v, int n) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n) {
    int queue[20], front = 0, rear = 0;
    int visitedB[10] = {0};

    queue[rear++] = start;
    visitedB[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 1; i <= n; i++) {
            if (graph[v][i] == 1 && visitedB[i] == 0) {
                queue[rear++] = i;
                visitedB[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    dfs(start, n);

    cout << "\nBFS: ";
    bfs(start, n);

    return 0;
}
