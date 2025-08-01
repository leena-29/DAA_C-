#include <iostream>
#include <vector>
#include <string>
using namespace std;

int designerPdfViewer(vector<int> h, string word) {
    int maxHeight = 0;
    for (char c : word) {
        int index = c - 'a';
        if (h[index] > maxHeight) {
            maxHeight = h[index];
        }
    }
    return maxHeight * word.length();
}

int main() {
    vector<int> h(26);
    for (int i = 0; i < 26; i++) {
        cin >> h[i];
    }
    string word;
    cin >> word;
    cout << designerPdfViewer(h, word) << endl;
    return 0;
}
