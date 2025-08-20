#include <bits/stdc++.h>
using namespace std;

long repeatedString(string s, long n) {
    long countInS = 0;
    for(char c : s) {
        if(c == 'a') countInS++;
    }

    long fullRepeats = n / s.size();
    long remainder = n % s.size();

    long total = fullRepeats * countInS;

    for(int i = 0; i < remainder; i++) {
        if(s[i] == 'a') total++;
    }

    return total;
}

int main() {
    string s;
    long n;
    cin >> s >> n;

    cout << repeatedString(s, n) << endl;
    return 0;
}
