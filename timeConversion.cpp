#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    string hh = s.substr(0, 2);
    string mmss = s.substr(2, 6);
    string period = s.substr(8, 2);
    int hour = stoi(hh);

    if (period == "AM") {
        if (hour == 12) hour = 0;
    } else {
        if (hour != 12) hour += 12;
    }

    stringstream ss;
    ss << setfill('0') << setw(2) << hour << mmss;
    return ss.str();
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    string result = timeConversion(s);
    fout << result << "\n";
    fout.close();
    return 0;
}
