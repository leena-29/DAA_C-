#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(i, '#') << endl;
    }
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}
