#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text[100], pattern[50];

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    int n = strlen(text);
    int m = strlen(pattern);

    cout << "Pattern found at positions: ";

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            cout << i << " ";
    }

    return 0;
}
