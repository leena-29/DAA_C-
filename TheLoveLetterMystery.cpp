#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());

    vector<int> result;
    int minDiff = INT_MAX;

    for (int i = 1; i < arr.size(); i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.clear();
            result.push_back(arr[i - 1]);
            result.push_back(arr[i]);
        } else if (diff == minDiff) {
            result.push_back(arr[i - 1]);
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = closestNumbers(arr);
    for (int x : ans) cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string s) {
    int n = s.size();
    int operations = 0;
    
    // Compare characters from both ends toward the center
    for(int i = 0; i < n / 2; i++) {
        operations += abs(s[i] - s[n - i - 1]);
    }
    
    return operations;
}

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        string s;
        cin >> s;
        cout << theLoveLetterMystery(s) << endl;
    }
    
    return 0;
}
