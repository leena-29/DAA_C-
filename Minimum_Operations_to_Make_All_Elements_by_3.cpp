#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for (int x : nums) {
            if (x % 3 != 0) {
                operations++;
            }
        }
        return operations;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.minimumOperations(nums) << endl;  // Expected output: 3
    return 0;
}
