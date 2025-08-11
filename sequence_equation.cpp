#include <iostream>
#include <vector>
using namespace std;

vector<int> permutationEquation(vector<int> p) {
    int n = p.size();
    vector<int> position(n + 1);
    
    // Store the position of each value
    for (int i = 0; i < n; i++) {
        position[p[i]] = i + 1;
    }
    
    vector<int> result;
    for (int x = 1; x <= n; x++) {
        int y = position[position[x]];
        result.push_back(y);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> result = permutationEquation(p);
    for (int val : result) {
        cout << val << endl;
    }
    
    return 0;
}
