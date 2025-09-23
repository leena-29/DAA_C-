#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // remove adjacent pair
        } else {
            st.push(c);
        }
    }
    
    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    
    return result.empty() ? "Empty String" : result;
}

int main() {
    string s;
    cin >> s;
    cout << superReducedString(s) << endl;
    return 0;
}
