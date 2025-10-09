#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */


string pangrams(string s) {
    vector<bool> alphabet(26, false);
    
    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            alphabet[c - 'a'] = true;
        }
    }
    
    for (bool present : alphabet) {
        if (!present)
            return "not pangram";
    }
    return "pangram";
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
