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

    int d = 256;        // number of characters
    int q = 101;        // prime number for hashing

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p = 0;  // hash for pattern
    int t = 0;  // hash for text window

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    cout << "Pattern found at positions: ";

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << i << " ";
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + 1]) % q;
            if (t < 0)
                t += q;
        }
    }

    return 0;
}
