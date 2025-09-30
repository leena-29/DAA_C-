#include <bits/stdc++.h>
using namespace std;

int minimumNumber(int n, string password) {
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    bool hasDigit = false, hasLower = false, hasUpper = false, hasSpecial = false;

    for (char c : password) {
        if (numbers.find(c) != string::npos) hasDigit = true;
        else if (lower_case.find(c) != string::npos) hasLower = true;
        else if (upper_case.find(c) != string::npos) hasUpper = true;
        else if (special_characters.find(c) != string::npos) hasSpecial = true;
    }

    int missingTypes = 0;
    if (!hasDigit) missingTypes++;
    if (!hasLower) missingTypes++;
    if (!hasUpper) missingTypes++;
    if (!hasSpecial) missingTypes++;

    // Password must also be at least 6 characters long
    return max(missingTypes, 6 - n);
}

int main() {
    int n;
    string password;
    cin >> n;
    cin >> password;

    cout << minimumNumber(n, password) << endl;
    return 0;
}
